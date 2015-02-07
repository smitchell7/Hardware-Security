----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:26:47 01/31/2015 
-- Design Name: 
-- Module Name:    reg32_top - Behavioral 
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

entity reg32_top is
    Port ( D : in  STD_LOGIC_VECTOR (31 downto 0);
           EN : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (31 downto 0));
end reg32_top;

architecture arch of reg32_top is    


--   COMPONENT reg32
--   PORT( in_15_to_0	:	IN	STD_LOGIC_VECTOR (15 DOWNTO 0); 
--          OUT_15_to_0	:	OUT	STD_LOGIC_VECTOR (15 DOWNTO 0); 
--          CE1	:	IN	STD_LOGIC; 
--          CLK1	:	IN	STD_LOGIC; 
--          RESET1	:	IN	STD_LOGIC; 
--          CE2	:	IN	STD_LOGIC; 
--          CLK2	:	IN	STD_LOGIC; 
--          RESET2	:	IN	STD_LOGIC; 
--          In_31_to_16	:	IN	STD_LOGIC_VECTOR (15 DOWNTO 0); 
--          OUT_31_to_16	:	OUT	STD_LOGIC_VECTOR (15 DOWNTO 0));
--   END COMPONENT;

begin

  process(CLK, RESET, D)
  begin
    if(CLK'event and CLK = '1') then
      if(RESET = '1') then 
        Q <= (Others => '0');
      elsif(EN = '1') then
        Q <= D;
      end if;
    end if;
  end process;


--   reg: reg32 PORT MAP(
--		in_15_to_0 => D(15 downto 0), 
--		OUT_15_to_0 => Q(15 downto 0), 
--		CE1 => EN, 
--		CLK1 => CLK, 
--		RESET1 => RESET, 
--		CE2 => EN, 
--		CLK2 => CLK, 
--		RESET2 => RESET, 
--		In_31_to_16 => D(31 downto 16), 
--		OUT_31_to_16 => Q(31 downto 16)
--   );


end arch;

