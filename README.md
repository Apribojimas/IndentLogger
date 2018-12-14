# IndentLogger
Simple logger class with indention possibility

During logging we need track how deep dip into functions. Logger add indent for every level.
Example of logs:

13:43:49.598 >  main() - (.../main.cpp:   39)
13:43:49.604   >  level1() - (.../main.cpp:   22) -- Parameter: 0
13:43:49.605     |  level1() - (.../main.cpp:   32) -- Index: 0
13:43:49.605     |  level1() - (.../main.cpp:   32) -- Index: 1
13:43:49.606     |  level1() - (.../main.cpp:   32) -- Index: 2
13:43:49.606     |  level1() - (.../main.cpp:   32) -- Index: 3
13:43:49.606     |  level1() - (.../main.cpp:   32) -- Index: 4
13:43:49.606     |  level1() - (.../main.cpp:   32) -- Index: 5
13:43:49.607     |  level1() - (.../main.cpp:   32) -- Index: 6
13:43:49.607   <  level1() - (.../main.cpp) -- Elapsed time: 2.991 ms.
13:43:49.607   >  level1() - (.../main.cpp:   22) -- Parameter: 1
13:43:49.607     >  level1() - (.../main.cpp:   25) -- Enter level2
13:43:49.608       >  level2() - (.../main.cpp:    7)
13:43:49.608         |  level2() - (.../main.cpp:    9) -- Start process ...
13:43:49.608         |  level2() - (.../main.cpp:   12) -- Logger indent is: 8
13:43:49.608         |  level2() - (.../main.cpp:   13) -- Logger elapsed time: 6684064
13:43:49.608         |  level2() - (.../main.cpp:   16) -- End process ...
13:43:49.609       <  level2() - (.../main.cpp) -- Elapsed time: 0.998 ms.
13:43:49.609     <  level1() - (.../main.cpp) -- Elapsed time: 1.996 ms.
13:43:49.609   <  level1() - (.../main.cpp) -- Elapsed time: 1.996 ms.
13:43:49.609 <  main() - (.../main.cpp) -- Elapsed time: 10.973 ms.
