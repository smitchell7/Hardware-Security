#include "visa.h"
#include <stdio.h>
#include <memory.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>
#define NUM_SAMPLES 2
long query(ViSession vi, char * cmd, std::ofstream * file, unsigned char len);
int check_state(ViSession vi, ViChar * buffer);

// This example opens a specific GPIB device, does an *idn query
// and prints the result.
int main(int argc, char* argv[])
{
	ViSession rm = VI_NULL, vi = VI_NULL;
	ViStatus status;
	ViChar buffer[256];
	ViChar filename[50];
	ViUInt32 retCnt;
	time_t rawtime;
	struct tm timeinfo;
	time (&rawtime);
	localtime_s(&timeinfo, &rawtime);
	std::ofstream output_file;
	strftime((char *)filename, 80, "%d%b%H%M.txt", &timeinfo);
	output_file.open(filename);

	// Open a default session
	status = viOpenDefaultRM(&rm);
	if (status < VI_SUCCESS) goto error;
// Open the GPIB device at primary address 1, GPIB board 8
	status = viOpen(rm, "USB::0x0699::0x0374::C013211::INSTR", VI_NULL, VI_NULL,
	                &vi);
	if (status < VI_SUCCESS) goto error;
// Send an ID query.
	status = viWrite(vi, (ViBuf) "*idn?", 5, &retCnt);
	if (status < VI_SUCCESS) goto error;
// Clear the buffer and read the response
	memset(buffer, 0, sizeof(buffer));
	status = viRead(vi, (ViBuf) buffer, sizeof(buffer), &retCnt);
	if (status < VI_SUCCESS) goto error;
// Print the response
	printf("id: %s\n", buffer);

	viSetAttribute(vi, VI_ATTR_FILE_APPEND_EN, VI_FALSE);
	query(vi, "*idn?", &output_file, 5);
	viSetAttribute(vi, VI_ATTR_FILE_APPEND_EN, VI_TRUE);
	viSetAttribute(vi, VI_ATTR_ASRL_END_OUT, VI_ASRL_END_NONE);
	

	/********************************************************
	 * Now we can start measurement.
	 *
	 *
	 *
	 *
	 *
	********************************************************/
	// Determine y-increment.

	for (int i = 0; i < NUM_SAMPLES; i++)
	{
		query(vi, "*idn?", &output_file, 5);
		viWrite(vi, (ViBuf)"ACQ:STATE ON", 12, &retCnt);
		while (check_state(vi, buffer) == 1)
		{
			Sleep(100);
		}
		status = viWrite(vi, (ViBuf)"DATA:SOURCE CH1", 15, &retCnt);
		if (status < VI_SUCCESS) goto error;
		query(vi, "CURVE?", &output_file, 6);
		status = viWrite(vi, (ViBuf)"DATA:SOURCE CH2", 15, &retCnt);
		if (status < VI_SUCCESS) goto error;
		query(vi, "CURVE?", &output_file, 6);
		status = viWrite(vi, (ViBuf)"DATA:SOURCE MATH", 17, &retCnt);
		if (status < VI_SUCCESS) goto error;
		query(vi, "CURVE?", &output_file, 6);
	}
	//*/

	// Clean up
	viClose(vi); // Not needed, but makes things a bit more
// understandable
	viClose(rm); // Closes resource manager and any sessions
// opened with it
	return 0;
error:
// Report error and clean up
	viStatusDesc(vi, status, buffer);
	fprintf(stderr, "failure: % s\n", buffer);
	if (rm != VI_NULL) {
		viClose(rm);
	}
	system("pause");
	return 1;
}
int check_state(ViSession vi, ViChar * buffer)
{
	viWrite(vi, (ViBuf)"ACQ:STATE?", 10, 0);
	//if (status < VI_SUCCESS) goto error;
	// Clear the buffer and read the response
	memset(buffer, 0, sizeof(buffer));
	viRead(vi, (ViBuf)buffer, sizeof(buffer), 0);
	printf("%s\n\n", buffer);
	return atoi(buffer);

} 
long query(ViSession vi, char * cmd,  std::ofstream * file, unsigned char len)
{
	ViStatus status;
	ViUInt32 retCnt;
	double data[500];
	
	
	status = viWrite(vi, (ViBuf) cmd, 11, &retCnt);
	if (status < VI_SUCCESS) goto error;
	// Clear the buffer and read the response
	//memset(buffer, 0, sizeof(buffer));
	//status = viRead(vi, (ViBuf)buffer, sizeof(buffer), &retCnt);
	//status = viReadToFile(vi, file, 50, 0);
	status = viSScanf(vi, (ViBuf)data, (ViString)"%y");
	for (int i = 0; i < 500; i++)
		file[0] << data[i] << ", ";
	file[0] << std::endl;
	if (status < VI_SUCCESS) goto error;
	return 0;
error:
	ViChar buffer[100];
	// Report error and clean up
	viStatusDesc(vi, status, buffer);
//	fprintf(stderr, "failure: % s\n", buffer);
	printf("Failure %s\n",buffer);
	system("pause");
	return 0;
}

