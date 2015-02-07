----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:54:26 01/29/2015 
-- Design Name: 
-- Module Name:    I - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity I is
    Port ( 
	        X    : in  STD_LOGIC_VECTOR (31 downto 0);
           Y    : in  STD_LOGIC_VECTOR (31 downto 0);
           Z    : in  STD_LOGIC_VECTOR (31 downto 0);
           RESULT : out  STD_LOGIC_VECTOR (31 downto 0)
			 );
end I;

architecture arch of I is

begin

RESULT <= (Y xor (X or (not Z)));

end arch;

