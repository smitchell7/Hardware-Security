----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:45:06 01/29/2015 
-- Design Name: 
-- Module Name:    md5_top - Behavioral 
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

entity md5_top is
    Port ( 
			     SW     : in  STD_LOGIC_VECTOR (7 downto 0);
           CLK    : in  STD_LOGIC;
           RESET  : in  STD_LOGIC;
           LED       : out  STD_LOGIC_VECTOR (3 downto 0));
end md5_top;

architecture arch of md5_top is

  component add32 IS
    port (
      A : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      B : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      S : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
    );
  end component;

	signal sig       : std_logic_vector(31 downto 0)  := (others => '0');
	signal result    : std_logic_vector(31 downto 0)  := (others => '0');
	
	signal candidate :  std_logic_vector(511 downto 0) := 
	x"00000000_00000038_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_80616161_61616161";
	  alias can0  : std_logic_vector(31 downto 0)  is candidate(31 downto 0);
	  alias can1  : std_logic_vector(31 downto 0)  is candidate(63 downto 32);
	  alias can2  : std_logic_vector(31 downto 0)  is candidate(95 downto 64);
	  alias can3  : std_logic_vector(31 downto 0)  is candidate(127 downto 96);
	  alias can4  : std_logic_vector(31 downto 0)  is candidate(159 downto 128);
	  alias can5  : std_logic_vector(31 downto 0)  is candidate(191 downto 160);
	  alias can6  : std_logic_vector(31 downto 0)  is candidate(223 downto 192);
	  alias can7  : std_logic_vector(31 downto 0)  is candidate(255 downto 224);
	  alias can8  : std_logic_vector(31 downto 0)  is candidate(287 downto 256);
	  alias can9  : std_logic_vector(31 downto 0)  is candidate(319 downto 288);
	  alias can10 : std_logic_vector(31 downto 0)  is candidate(351 downto 320);
	  alias can11 : std_logic_vector(31 downto 0)  is candidate(383 downto 352);
	  alias can12 : std_logic_vector(31 downto 0)  is candidate(415 downto 384);
	  alias can13 : std_logic_vector(31 downto 0)  is candidate(447 downto 416);
	  alias can14 : std_logic_vector(31 downto 0)  is candidate(479 downto 448);
	  alias can15 : std_logic_vector(31 downto 0)  is candidate(511 downto 480);

  signal a00,  b00,  c00,  d00 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a01,  b01,  c01,  d01 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a02,  b02,  c02,  d02 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a03,  b03,  c03,  d03 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a04,  b04,  c04,  d04 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a05,  b05,  c05,  d05 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a06,  b06,  c06,  d06 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a07,  b07,  c07,  d07 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a08,  b08,  c08,  d08 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a09,  b09,  c09,  d09 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a010, b010, c010, d010 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a011, b011, c011, d011 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a012, b012, c012, d012 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a013, b013, c013, d013 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a014, b014, c014, d014 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a015, b015, c015, d015 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a10,  b10,  c10,  d10 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a11,  b11,  c11,  d11 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a12,  b12,  c12,  d12 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a13,  b13,  c13,  d13 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a14,  b14,  c14,  d14 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a15,  b15,  c15,  d15 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a16,  b16,  c16,  d16 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a17,  b17,  c17,  d17 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a18,  b18,  c18,  d18 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a19,  b19,  c19,  d19 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a110, b110, c110, d110 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a111, b111, c111, d111 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a112, b112, c112, d112 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a113, b113, c113, d113 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a114, b114, c114, d114 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a115, b115, c115, d115 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a20,  b20,  c20,  d20 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a21,  b21,  c21,  d21 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a22,  b22,  c22,  d22 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a23,  b23,  c23,  d23 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a24,  b24,  c24,  d24 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a25,  b25,  c25,  d25 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a26,  b26,  c26,  d26 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a27,  b27,  c27,  d27 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a28,  b28,  c28,  d28 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a29,  b29,  c29,  d29 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a210, b210, c210, d210 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a211, b211, c211, d211 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a212, b212, c212, d212 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a213, b213, c213, d213 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a214, b214, c214, d214 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a215, b215, c215, d215 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a30,  b30,  c30,  d30 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a31,  b31,  c31,  d31 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a32,  b32,  c32,  d32 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a33,  b33,  c33,  d33 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a34,  b34,  c34,  d34 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a35,  b35,  c35,  d35 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a36,  b36,  c36,  d36 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a37,  b37,  c37,  d37 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a38,  b38,  c38,  d38 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a39,  b39,  c39,  d39 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a310, b310, c310, d310 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a311, b311, c311, d311 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a312, b312, c312, d312 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a313, b313, c313, d313 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a314, b314, c314, d314 : std_logic_vector(31 downto 0) := (Others => '0');
  signal a315, b315, c315, d315 : std_logic_vector(31 downto 0) := (Others => '0');

  signal a_final, b_final, c_final, d_final : std_logic_vector(31 downto 0) := (Others => '0');
  signal hash : std_logic_vector(127 downto 0) := (Others => '0');


component F is
    Port ( 
			  X    : in  STD_LOGIC_VECTOR (31 downto 0);
           Y    : in  STD_LOGIC_VECTOR (31 downto 0);
           Z    : in  STD_LOGIC_VECTOR (31 downto 0);
           RESULT : out  STD_LOGIC_VECTOR (31 downto 0)
			 );
end component;

component reg32_top is
    Port ( D     : in  STD_LOGIC_VECTOR (31 downto 0);
           EN    : in  STD_LOGIC;
           CLK   : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q       : out  STD_LOGIC_VECTOR (31 downto 0));
end component;

component round0 is
  GENERIC(THIRTY_ONE_MINUS_S : natural:= 24;
          THIRTY_ONE_MINUS_S_PLUS_ONE : natural:= 25);
    Port ( A        : in  STD_LOGIC_VECTOR (31 downto 0);
           B        : in  STD_LOGIC_VECTOR (31 downto 0);
           C        : in  STD_LOGIC_VECTOR (31 downto 0);
           D        : in  STD_LOGIC_VECTOR (31 downto 0);
           K        : in  STD_LOGIC_VECTOR (31 downto 0);
           T        : in  STD_LOGIC_VECTOR (31 downto 0);
           RESET    : in std_logic;
           CLK      : in std_logic;
              A_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              B_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              C_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              D_OUT   : out  STD_LOGIC_VECTOR (31 downto 0));
end component;

component round1 is
  GENERIC(THIRTY_ONE_MINUS_S : natural:= 24;
          THIRTY_ONE_MINUS_S_PLUS_ONE : natural:= 25);
    Port ( A        : in  STD_LOGIC_VECTOR (31 downto 0);
           B        : in  STD_LOGIC_VECTOR (31 downto 0);
           C        : in  STD_LOGIC_VECTOR (31 downto 0);
           D        : in  STD_LOGIC_VECTOR (31 downto 0);
           K        : in  STD_LOGIC_VECTOR (31 downto 0);
           T        : in  STD_LOGIC_VECTOR (31 downto 0);
           RESET    : in std_logic;
           CLK      : in std_logic;
              A_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              B_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              C_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              D_OUT   : out  STD_LOGIC_VECTOR (31 downto 0));
end component;

component round2 is
  GENERIC(THIRTY_ONE_MINUS_S : natural:= 24;
          THIRTY_ONE_MINUS_S_PLUS_ONE : natural:= 25);
    Port ( A        : in  STD_LOGIC_VECTOR (31 downto 0);
           B        : in  STD_LOGIC_VECTOR (31 downto 0);
           C        : in  STD_LOGIC_VECTOR (31 downto 0);
           D        : in  STD_LOGIC_VECTOR (31 downto 0);
           K        : in  STD_LOGIC_VECTOR (31 downto 0);
           T        : in  STD_LOGIC_VECTOR (31 downto 0);
           RESET    : in std_logic;
           CLK      : in std_logic;
              A_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              B_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              C_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              D_OUT   : out  STD_LOGIC_VECTOR (31 downto 0));
end component;

component round3 is
  GENERIC(THIRTY_ONE_MINUS_S : natural:= 24;
          THIRTY_ONE_MINUS_S_PLUS_ONE : natural:= 25);
    Port ( A        : in  STD_LOGIC_VECTOR (31 downto 0);
           B        : in  STD_LOGIC_VECTOR (31 downto 0);
           C        : in  STD_LOGIC_VECTOR (31 downto 0);
           D        : in  STD_LOGIC_VECTOR (31 downto 0);
           K        : in  STD_LOGIC_VECTOR (31 downto 0);
           T        : in  STD_LOGIC_VECTOR (31 downto 0);
           RESET    : in std_logic;
           CLK      : in std_logic;
              A_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              B_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              C_OUT   : out  STD_LOGIC_VECTOR (31 downto 0);
              D_OUT   : out  STD_LOGIC_VECTOR (31 downto 0));
end component;

begin

--ROUND0                  
  r0_0 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 24,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 25)
    PORT MAP ( A => x"67452301", B => x"efcdab89", C => x"98badcfe", D => x"10325476", 
               K => can0, T => x"d76aa478", RESET => RESET, CLK => CLK,
               A_OUT => a00, B_OUT => b00, C_OUT => c00, D_OUT => d00);
  r0_1 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 19,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 20)
    PORT MAP ( A => d00, B => a00, C => b00, D => c00,
               K => can1, T => x"e8c7b756", RESET => RESET, CLK => CLK,
               A_OUT => a01, B_OUT => b01, C_OUT => c01, D_OUT => d01);
  r0_2 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 14,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 15)
    PORT MAP ( A => d01, B => a01, C => b01, D => c01, 
               K => can2, T => x"242070db", RESET => RESET, CLK => CLK,
               A_OUT => a02, B_OUT => b02, C_OUT => c02, D_OUT => d02);
  r0_3 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 9,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 10)
    PORT MAP ( A => d02, B => a02, C => b02, D => c02,
               K => can3, T => x"c1bdceee", RESET => RESET, CLK => CLK,
               A_OUT => a03, B_OUT => b03, C_OUT => c03, D_OUT => d03);
  r0_4 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 24,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 25)
    PORT MAP ( A => d03, B => a03, C => b03, D => c03,
               K => can4, T => x"f57c0faf", RESET => RESET, CLK => CLK,
               A_OUT => a04, B_OUT => b04, C_OUT => c04, D_OUT => d04);
  r0_5 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 19,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 20)
    PORT MAP ( A => d04, B => a04, C => b04, D => c04,
               K => can5, T => x"4787c62a", RESET => RESET, CLK => CLK,
               A_OUT => a05, B_OUT => b05, C_OUT => c05, D_OUT => d05);
  r0_6 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 14,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 15)
    PORT MAP ( A => d05 , B => a05, C => b05, D => c05,
               K => can6, T => x"a8304613", RESET => RESET, CLK => CLK,
               A_OUT => a06, B_OUT => b06, C_OUT => c06, D_OUT => d06);
  r0_7 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 9,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 10)
    PORT MAP ( A =>  d06, B => a06, C => b06, D => c06,
               K => can7, T => x"fd469501", RESET => RESET, CLK => CLK,
               A_OUT => a07, B_OUT => b07, C_OUT => c07, D_OUT => d07);
  r0_8 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 24,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 25)
    PORT MAP ( A =>  d07, B => a07, C => b07, D => c07,
               K => can8, T => x"698098d8", RESET => RESET, CLK => CLK,
               A_OUT => a08, B_OUT => b08, C_OUT => c08, D_OUT => d08);
  r0_9 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 19,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 20)
    PORT MAP ( A =>  d08, B => a08, C => b08, D => c08,
               K => can9, T => x"8b44f7af", RESET => RESET, CLK => CLK,
               A_OUT => a09, B_OUT => b09, C_OUT => c09, D_OUT => d09);
  r0_10 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 14,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 15)
    PORT MAP ( A =>  d09, B => a09, C => b09, D => c09,
               K => can10, T => x"ffff5bb1", RESET => RESET, CLK => CLK,
               A_OUT => a010, B_OUT => b010, C_OUT => c010, D_OUT => d010);
  r0_11 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 9,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 10)
    PORT MAP ( A =>  d010, B => a010, C => b010, D => c010,
               K => can11, T => x"895cd7be", RESET => RESET, CLK => CLK,
               A_OUT => a011, B_OUT => b011, C_OUT => c011, D_OUT => d011);
  r0_12 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 24,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 25)
    PORT MAP ( A =>  d011, B => a011, C => b011, D => c011,
               K => can12, T => x"6b901122", RESET => RESET, CLK => CLK,
               A_OUT => a012, B_OUT => b012, C_OUT => c012, D_OUT => d012);
  r0_13 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 19,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 20)
    PORT MAP ( A =>  d012, B => a012, C => b012, D => c012,
               K => can13, T => x"fd987193", RESET => RESET, CLK => CLK,
               A_OUT => a013, B_OUT => b013, C_OUT => c013, D_OUT => d013);
  r0_14 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 14,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 15)
    PORT MAP ( A =>  d013, B => a013, C => b013, D => c013,
               K => can14, T => x"a679438e", RESET => RESET, CLK => CLK,
               A_OUT => a014, B_OUT => b014, C_OUT => c014, D_OUT => d014);
  r0_15 : round0 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 9,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 10)
    PORT MAP ( A =>  d014, B => a014, C => b014, D => c014,
               K => can15, T => x"49b40821", RESET => RESET, CLK => CLK,
               A_OUT => a015, B_OUT => b015, C_OUT => c015, D_OUT => d015);
--End ROUND0

--ROUND1                  
  r1_0 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 26,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 27)
    PORT MAP ( A => d015, B => a015, C => b015, D => c015,
               K => can1, T => x"f61e2562", RESET => RESET, CLK => CLK,
               A_OUT => a10, B_OUT => b10, C_OUT => c10, D_OUT => d10);
  r1_1 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 22,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 23)
    PORT MAP ( A => d10, B => a10, C => b10, D => c10,
               K => can6, T => x"c040b340", RESET => RESET, CLK => CLK,
               A_OUT => a11, B_OUT => b11, C_OUT => c11, D_OUT => d11);
  r1_2 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 17,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 18)
    PORT MAP ( A => d11, B => a11, C => b11, D => c11, 
               K => can11, T => x"265e5a51", RESET => RESET, CLK => CLK,
               A_OUT => a12, B_OUT => b12, C_OUT => c12, D_OUT => d12);
  r1_3 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 11,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 12)
    PORT MAP ( A => d12, B => a12, C => b12, D => c12,
               K => can0, T => x"e9b6c7aa", RESET => RESET, CLK => CLK,
               A_OUT => a13, B_OUT => b13, C_OUT => c13, D_OUT => d13);
  r1_4 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 26,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 27)
    PORT MAP ( A => d13, B => a13, C => b13, D => c13,
               K => can5, T => x"d62f105d", RESET => RESET, CLK => CLK,
               A_OUT => a14, B_OUT => b14, C_OUT => c14, D_OUT => d14);
  r1_5 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 22,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 23)
    PORT MAP ( A => d14, B => a14, C => b14, D => c14,
               K => can10, T => x"02441453", RESET => RESET, CLK => CLK,
               A_OUT => a15, B_OUT => b15, C_OUT => c15, D_OUT => d15);
  r1_6 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 17,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 18)
    PORT MAP ( A => d15 , B => a15, C => b15, D => c15,
               K => can15, T => x"d8a1e681", RESET => RESET, CLK => CLK,
               A_OUT => a16, B_OUT => b16, C_OUT => c16, D_OUT => d16);
  r1_7 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 11,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 12)
    PORT MAP ( A =>  d16, B => a16, C => b16, D => c16,
               K => can4, T => x"e7d3fbc8", RESET => RESET, CLK => CLK,
               A_OUT => a17, B_OUT => b17, C_OUT => c17, D_OUT => d17);
  r1_8 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 26,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 27)
    PORT MAP ( A =>  d17, B => a17, C => b17, D => c17,
               K => can9, T => x"21e1cde6", RESET => RESET, CLK => CLK,
               A_OUT => a18, B_OUT => b18, C_OUT => c18, D_OUT => d18);
  r1_9 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 22,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 23)
    PORT MAP ( A =>  d18, B => a18, C => b18, D => c18,
               K => can14, T => x"c33707d6", RESET => RESET, CLK => CLK,
               A_OUT => a19, B_OUT => b19, C_OUT => c19, D_OUT => d19);
  r1_10 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 17,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 18)
    PORT MAP ( A =>  d19, B => a19, C => b19, D => c19,
               K => can3, T => x"f4d50d87", RESET => RESET, CLK => CLK,
               A_OUT => a110, B_OUT => b110, C_OUT => c110, D_OUT => d110);
  r1_11 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 11,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 12)
    PORT MAP ( A =>  d110, B => a110, C => b110, D => c110,
               K => can8, T => x"455a14ed", RESET => RESET, CLK => CLK,
               A_OUT => a111, B_OUT => b111, C_OUT => c111, D_OUT => d111);
  r1_12 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 26,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 27)
    PORT MAP ( A =>  d111, B => a111, C => b111, D => c111,
               K => can13, T => x"a9e3e905", RESET => RESET, CLK => CLK,
               A_OUT => a112, B_OUT => b112, C_OUT => c112, D_OUT => d112);
  r1_13 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 22,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 23)
    PORT MAP ( A =>  d112, B => a112, C => b112, D => c112,
               K => can2, T => x"fcefa3f8", RESET => RESET, CLK => CLK,
               A_OUT => a113, B_OUT => b113, C_OUT => c113, D_OUT => d113);
  r1_14 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 17,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 18)
    PORT MAP ( A =>  d113, B => a113, C => b113, D => c113,
               K => can7, T => x"676f02d9", RESET => RESET, CLK => CLK,
               A_OUT => a114, B_OUT => b114, C_OUT => c114, D_OUT => d114);
  r1_15 : round1 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 11,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 12)
    PORT MAP ( A =>  d114, B => a114, C => b114, D => c114,
               K => can12, T => x"8d2a4c8a", RESET => RESET, CLK => CLK,
               A_OUT => a115, B_OUT => b115, C_OUT => c115, D_OUT => d115);
--End round1

--ROUND2                  
  r2_0 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 27,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 28)
    PORT MAP ( A => d115, B => a115, C => b115, D => c115,
               K => can5, T => x"fffa3942", RESET => RESET, CLK => CLK,
               A_OUT => a20, B_OUT => b20, C_OUT => c20, D_OUT => d20);
  r2_1 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 20,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 21)
    PORT MAP ( A => d20, B => a20, C => b20, D => c20,
               K => can8, T => x"8771f681", RESET => RESET, CLK => CLK,
               A_OUT => a21, B_OUT => b21, C_OUT => c21, D_OUT => d21);
  r2_2 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 15,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 16)
    PORT MAP ( A => d21, B => a21, C => b21, D => c21, 
               K => can11, T => x"6d9d6122", RESET => RESET, CLK => CLK,
               A_OUT => a22, B_OUT => b22, C_OUT => c22, D_OUT => d22);
  r2_3 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 8,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 9)
    PORT MAP ( A => d22, B => a22, C => b22, D => c22,
               K => can14, T => x"fde5380c", RESET => RESET, CLK => CLK,
               A_OUT => a23, B_OUT => b23, C_OUT => c23, D_OUT => d23);
  r2_4 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 27,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 28)
    PORT MAP ( A => d23, B => a23, C => b23, D => c23,
               K => can1, T => x"a4beea44", RESET => RESET, CLK => CLK,
               A_OUT => a24, B_OUT => b24, C_OUT => c24, D_OUT => d24);
  r2_5 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 20,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 21)
    PORT MAP ( A => d24, B => a24, C => b24, D => c24,
               K => can4, T => x"4bdecfa9", RESET => RESET, CLK => CLK,
               A_OUT => a25, B_OUT => b25, C_OUT => c25, D_OUT => d25);
  r2_6 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 15,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 16)
    PORT MAP ( A => d25 , B => a25, C => b25, D => c25,
               K => can7, T => x"f6bb4b60", RESET => RESET, CLK => CLK,
               A_OUT => a26, B_OUT => b26, C_OUT => c26, D_OUT => d26);
  r2_7 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 8,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 9)
    PORT MAP ( A =>  d26, B => a26, C => b26, D => c26,
               K => can10, T => x"bebfbc70", RESET => RESET, CLK => CLK,
               A_OUT => a27, B_OUT => b27, C_OUT => c27, D_OUT => d27);
  r2_8 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 27,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 28)
    PORT MAP ( A =>  d27, B => a27, C => b27, D => c27,
               K => can13, T => x"289b7ec6", RESET => RESET, CLK => CLK,
               A_OUT => a28, B_OUT => b28, C_OUT => c28, D_OUT => d28);
  r2_9 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 20,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 21)
    PORT MAP ( A =>  d28, B => a28, C => b28, D => c28,
               K => can0, T => x"eaa127fa", RESET => RESET, CLK => CLK,
               A_OUT => a29, B_OUT => b29, C_OUT => c29, D_OUT => d29);
  r2_10 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 15,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 16)
    PORT MAP ( A =>  d29, B => a29, C => b29, D => c29,
               K => can3, T => x"d4ef3085", RESET => RESET, CLK => CLK,
               A_OUT => a210, B_OUT => b210, C_OUT => c210, D_OUT => d210);
  r2_11 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 8,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 9)
    PORT MAP ( A =>  d210, B => a210, C => b210, D => c210,
               K => can6, T => x"04881d05", RESET => RESET, CLK => CLK,
               A_OUT => a211, B_OUT => b211, C_OUT => c211, D_OUT => d211);
  r2_12 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 27,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 28)
    PORT MAP ( A =>  d211, B => a211, C => b211, D => c211,
               K => can9, T => x"d9d4d039", RESET => RESET, CLK => CLK,
               A_OUT => a212, B_OUT => b212, C_OUT => c212, D_OUT => d212);
  r2_13 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 20,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 21)
    PORT MAP ( A =>  d212, B => a212, C => b212, D => c212,
               K => can12, T => x"e6db99e5", RESET => RESET, CLK => CLK,
               A_OUT => a213, B_OUT => b213, C_OUT => c213, D_OUT => d213);
  r2_14 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 15,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 16)
    PORT MAP ( A =>  d213, B => a213, C => b213, D => c213,
               K => can15, T => x"1fa27cf8", RESET => RESET, CLK => CLK,
               A_OUT => a214, B_OUT => b214, C_OUT => c214, D_OUT => d214);
  r2_15 : round2 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 8,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 9)
    PORT MAP ( A =>  d214, B => a214, C => b214, D => c214,
               K => can2, T => x"c4ac5665", RESET => RESET, CLK => CLK,
               A_OUT => a215, B_OUT => b215, C_OUT => c215, D_OUT => d215);
--End ROUND2

--ROUND3                  
  r3_0 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 25,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 26)
    PORT MAP ( A => d215, B => a215, C => b215, D => c215,
               K => can0, T => x"f4292244", RESET => RESET, CLK => CLK,
               A_OUT => a30, B_OUT => b30, C_OUT => c30, D_OUT => d30);
  r3_1 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 21,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 22)
    PORT MAP ( A => d30, B => a30, C => b30, D => c30,
               K => can7, T => x"432aff97", RESET => RESET, CLK => CLK,
               A_OUT => a31, B_OUT => b31, C_OUT => c31, D_OUT => d31);
  r3_2 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 16,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 17)
    PORT MAP ( A => d31, B => a31, C => b31, D => c31, 
               K => can14, T => x"ab9423a7", RESET => RESET, CLK => CLK,
               A_OUT => a32, B_OUT => b32, C_OUT => c32, D_OUT => d32);
  r3_3 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 10,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 11)
    PORT MAP ( A => d32, B => a32, C => b32, D => c32,
               K => can5, T => x"fc93a039", RESET => RESET, CLK => CLK,
               A_OUT => a33, B_OUT => b33, C_OUT => c33, D_OUT => d33);
  r3_4 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 25,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 26)
    PORT MAP ( A => d33, B => a33, C => b33, D => c33,
               K => can12, T => x"655b59c3", RESET => RESET, CLK => CLK,
               A_OUT => a34, B_OUT => b34, C_OUT => c34, D_OUT => d34);
  r3_5 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 21,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 22)
    PORT MAP ( A => d34, B => a34, C => b34, D => c34,
               K => can3, T => x"8f0ccc92", RESET => RESET, CLK => CLK,
               A_OUT => a35, B_OUT => b35, C_OUT => c35, D_OUT => d35);
  r3_6 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 16,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 17)
    PORT MAP ( A => d35 , B => a35, C => b35, D => c35,
               K => can10, T => x"ffeff47d", RESET => RESET, CLK => CLK,
               A_OUT => a36, B_OUT => b36, C_OUT => c36, D_OUT => d36);
  r3_7 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 10,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 11)
    PORT MAP ( A =>  d36, B => a36, C => b36, D => c36,
               K => can1, T => x"85845dd1", RESET => RESET, CLK => CLK,
               A_OUT => a37, B_OUT => b37, C_OUT => c37, D_OUT => d37);
  r3_8 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 25,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 26)
    PORT MAP ( A =>  d37, B => a37, C => b37, D => c37,
               K => can8, T => x"6fa87e4f", RESET => RESET, CLK => CLK,
               A_OUT => a38, B_OUT => b38, C_OUT => c38, D_OUT => d38);
  r3_9 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 21,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 22)
    PORT MAP ( A =>  d38, B => a38, C => b38, D => c38,
               K => can15, T => x"fe2ce6e0", RESET => RESET, CLK => CLK,
               A_OUT => a39, B_OUT => b39, C_OUT => c39, D_OUT => d39);
  r3_10 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 16,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 17)
    PORT MAP ( A =>  d39, B => a39, C => b39, D => c39,
               K => can6, T => x"a3014314", RESET => RESET, CLK => CLK,
               A_OUT => a310, B_OUT => b310, C_OUT => c310, D_OUT => d310);
  r3_11 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 10,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 11)
    PORT MAP ( A =>  d310, B => a310, C => b310, D => c310,
               K => can13, T => x"4e0811a1", RESET => RESET, CLK => CLK,
               A_OUT => a311, B_OUT => b311, C_OUT => c311, D_OUT => d311);
  r3_12 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 25,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 26)
    PORT MAP ( A =>  d311, B => a311, C => b311, D => c311,
               K => can4, T => x"f7537e82", RESET => RESET, CLK => CLK,
               A_OUT => a312, B_OUT => b312, C_OUT => c312, D_OUT => d312);
  r3_13 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 21,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 22)
    PORT MAP ( A =>  d312, B => a312, C => b312, D => c312,
               K => can11, T => x"bd3af235", RESET => RESET, CLK => CLK,
               A_OUT => a313, B_OUT => b313, C_OUT => c313, D_OUT => d313);
  r3_14 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 16,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 17)
    PORT MAP ( A =>  d313, B => a313, C => b313, D => c313,
               K => can2, T => x"2ad7d2bb", RESET => RESET, CLK => CLK,
               A_OUT => a314, B_OUT => b314, C_OUT => c314, D_OUT => d314);
  r3_15 : round3 
  GENERIC MAP (THIRTY_ONE_MINUS_S => 10,
          THIRTY_ONE_MINUS_S_PLUS_ONE => 11)
    PORT MAP ( A =>  d314, B => a314, C => b314, D => c314,
               K => can9, T => x"eb86d391", RESET => RESET, CLK => CLK,
               A_OUT => a315, B_OUT => b315, C_OUT => c315, D_OUT => d315);
--End ROUND3
add1 : add32
  port map(a => d315, b => x"67452301", s => a_final);
add2 : add32
  port map(a => a315, b => x"efcdab89", s => b_final);
add3 : add32
  port map(a => b315, b => x"98badcfe", s => c_final);
add4 : add32
  port map(a => c315, b => x"10325476", s => d_final);
--  a_final <= d315 + x"67452301";
--  b_final <= a315 + x"efcdab89";
--  c_final <= b315 + x"98badcfe";
--  d_final <= c315 + x"10325476";

  hash <= a_final( 7 downto  0) & 
          a_final(15 downto  8) & 
          a_final(23 downto 16) & 
          a_final(31 downto 24) & 
          b_final( 7 downto  0) & 
          b_final(15 downto  8) & 
          b_final(23 downto 16) & 
          b_final(31 downto 24) & 
          c_final( 7 downto  0) & 
          c_final(15 downto  8) & 
          c_final(23 downto 16) & 
          c_final(31 downto 24) & 
          d_final( 7 downto  0) & 
          d_final(15 downto  8) & 
          d_final(23 downto 16) & 
          d_final(31 downto 24);

F1 : F
    port map
		  (  X    => sig, Y    => x"11111111", Z    => x"11111111", RESULT => result
		  );
		  
LED(0) <= SW(0);
LED(1) <= SW(1);
LED(2) <= SW(1) and SW(2);
LED(3) <= hash(  0) or hash(  1) or hash(  2) or hash(  3) or hash(  4) or hash(  5) or hash(  6) or hash(  7) or hash(  8) or hash(  9) or hash( 10) or 
          hash( 11) or hash( 12) or hash( 13) or hash( 14) or hash( 15) or hash( 16) or hash( 17) or hash( 18) or hash( 19) or hash( 20) or hash( 21) or 
          hash( 22) or hash( 23) or hash( 24) or hash( 25) or hash( 26) or hash( 27) or hash( 28) or hash( 29) or hash( 30) or hash( 31) or hash( 32) or 
          hash( 33) or hash( 34) or hash( 35) or hash( 36) or hash( 37) or hash( 38) or hash( 39) or hash( 40) or hash( 41) or hash( 42) or hash( 43) or 
          hash( 44) or hash( 45) or hash( 46) or hash( 47) or hash( 48) or hash( 49) or hash( 50) or hash( 51) or hash( 52) or hash( 53) or hash( 54) or 
          hash( 55) or hash( 56) or hash( 57) or hash( 58) or hash( 59) or hash( 60) or hash( 61) or hash( 62) or hash( 63) or hash( 64) or hash( 65) or 
          hash( 66) or hash( 67) or hash( 68) or hash( 69) or hash( 70) or hash( 71) or hash( 72) or hash( 73) or hash( 74) or hash( 75) or hash( 76) or 
          hash( 77) or hash( 78) or hash( 79) or hash( 80) or hash( 81) or hash( 82) or hash( 83) or hash( 84) or hash( 85) or hash( 86) or hash( 87) or 
          hash( 88) or hash( 89) or hash( 90) or hash( 91) or hash( 92) or hash( 93) or hash( 94) or hash( 95) or hash( 96) or hash( 97) or hash( 98) or 
          hash( 99) or hash(100) or hash(101) or hash(102) or hash(103) or hash(104) or hash(105) or hash(106) or hash(107) or hash(108) or hash(109) or 
          hash(110) or hash(111) or hash(112) or hash(113) or hash(114) or hash(115) or hash(116) or hash(117) or hash(118) or hash(119) or hash(120) or 
          hash(121) or hash(122) or hash(123) or hash(124) or hash(125) or hash(126) or hash(127);


sig(0) <= SW(0);
sig(1) <= SW(1);
sig(2) <= SW(2);
sig(3) <= SW(3);
sig(4) <= SW(4);
sig(5) <= SW(5);
sig(6) <= SW(6);
sig(7) <= SW(7);



end arch;

