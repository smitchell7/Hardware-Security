----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:51:17 01/29/2015 
-- Design Name: 
-- Module Name:    G - Behavioral 
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

entity G is
    Port ( 
	        X    : in  STD_LOGIC_VECTOR (31 downto 0);
           Y    : in  STD_LOGIC_VECTOR (31 downto 0);
           Z    : in  STD_LOGIC_VECTOR (31 downto 0);
           RESULT : out  STD_LOGIC_VECTOR (31 downto 0)
			 );
end G;

architecture arch of G is

begin

RESULT <= (X and Z) or (Y and not Z);


end arch;

