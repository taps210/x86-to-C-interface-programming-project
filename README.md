# Bernardo-Fernandez-Group4-S16-x86-to-C-interface-programming-project

# Screenshot of the program output with the correctness check showing the same values for C and ASM
![image](https://github.com/taps210/x86-to-C-interface-programming-project/assets/126074320/db4661f5-0f3d-4c4a-ba03-6050a1d6d67a)

# Comparitive Execution Time
[C-assembly interface Testing.pdf](https://github.com/taps210/x86-to-C-interface-programming-project/files/14824869/C-assembly.interface.Testing.pdf)

# Short Analysis of the Performance of the Kernels
Based on the provided performance data, it's evident that the assembly (asm) kernel consistently outperforms the C kernel in terms of execution time across all vector sizes tested. Unfortunately, release mode yielded a time of zero for both kernels, most likely due to the fact that their runtimes were significantly faster. Instead, here is a summary of the findings from debug mode:

Vector size of 2^20:
Assembly kernel: Average execution time of 0.0018 seconds
C kernel: Average execution time of 0.002066666667 seconds

Vector size of 2^24:
Assembly kernel: Average execution time of 0.0255 seconds
C kernel: Average execution time of 0.03416666667 seconds

Vector size of 2^28:
Assembly kernel: Average execution time of 0.4894333333 seconds
C kernel: Average execution time of 0.7432 seconds

From these results, the speedup provided by the assembly implementation becomes more pronounced as the vector size increases, indicating that the efficiency of the assembly code scales well with larger data sets. The assembly kernel performed much faster than C because data is no longer fetched from the memory, instead it is directly manipulated in the CPU. This performance advantage underscores the benefits of hand-optimized assembly code for large datasets, especially when performance is critical. 
