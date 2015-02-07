----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:42:09 01/31/2015 
-- Design Name: 
-- Module Name:    round2 - arch 
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

entity round2 is
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
end round2;

architecture arch of round2 is

component H is
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

component add32 IS
  port (
    A : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    B : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    S : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
  );
end component;

signal res, h_cycle1, a_cycle2, a_cycle3, a_cycle2_in, a_cycle3_in : std_logic_vector(31 downto 0) := (Others => '0');
signal b1, b2 : std_logic_vector(31 downto 0) := (Others => '0');
signal c1, c2 : std_logic_vector(31 downto 0) := (Others => '0');
signal d1, d2 : std_logic_vector(31 downto 0) := (Others => '0');
signal a1, a2 : std_logic_vector(31 downto 0) := (Others => '0');
signal shift  : std_logic_vector(31 downto 0) := (Others => '0');

begin

H1 : H
    port map
		  (  X => B, Y => C, Z => D, RESULT => res);
--A logic		  
r1 : reg32_top
  port map(D => res, EN => '1', CLK => CLK, RESET => RESET, Q => h_cycle1);

add1 : add32
  port map(a => K, b => T, s => a1);

add2 : add32
  port map(a => A, b => h_cycle1, s => a2);

add3 : add32
  port map(a => a1, b => a2, s => a_cycle2_in);

r2 : reg32_top
  port map
	     (D => a_cycle2_in, EN => '1', CLK => CLK, RESET => RESET, Q => a_cycle2);

shift <= (a_cycle2(THIRTY_ONE_MINUS_S downto 0) & a_cycle2(31 downto (THIRTY_ONE_MINUS_S_PLUS_ONE)));

add4 : add32
  port map(a => shift, b => B, s => a_cycle3_in);

r3 : reg32_top
  port map
	     (D => a_cycle3_in, EN => '1', CLK => CLK, RESET => RESET, Q => a_cycle3);

--B logic -- register it at least once, maybe 3 times
Br1 : reg32_top
  port map
	     (D => B, EN => '1', CLK => CLK, RESET => RESET, Q => B_OUT);  

--C logic -- register it at least once, maybe 3 times
Cr1 : reg32_top
  port map
	     (D => C, EN => '1', CLK => CLK, RESET => RESET, Q => C_OUT);  

--D logic -- register it at least once, maybe 3 times
Dr1 : reg32_top
  port map
	     (D => D, EN => '1', CLK => CLK, RESET => RESET, Q => D_OUT); 

  A_OUT <= a_cycle3;




end arch;

