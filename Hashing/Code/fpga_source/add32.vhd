library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity add32 is
    Port ( A : in  std_logic_vector(31 downto 0);
           B : in  std_logic_vector(31 downto 0);
             S : out  std_logic_vector(31 downto 0)
    );
end add32;

architecture arch of add32 is


begin

  S <= A + B;
                                                                  
end arch;