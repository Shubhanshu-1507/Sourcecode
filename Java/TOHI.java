import java.io.*;  // Import for input/output
import java.math.*; // Import for mathematical operations (not required here but commonly used)
import java.util.*; // Import for utility classes (not required here but commonly used)

// Class to implement Tower of Hanoi problem
class TOHI {
    // Recursive function to solve Tower of Hanoi puzzle
    static void towerOfHanoi(int n, char from_rod, // 'from_rod' is the source rod where disks are initially placed
                             char to_rod,   // 'to_rod' is the destination rod where disks need to be moved
                             char aux_rod)  // 'aux_rod' is the auxiliary rod used during the disk transfer
    {
        // Base case: If no disks (n == 0), simply return
        if (n == 0) {
            return;
        }
        
        // Move the top n-1 disks from 'from_rod' to 'aux_rod', using 'to_rod' as auxiliary
        towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
        
        // Move the nth disk from 'from_rod' to 'to_rod'
        System.out.println("Move disk " + n + " from rod " + from_rod + " to rod " + to_rod);
        
        // Move the n-1 disks from 'aux_rod' to 'to_rod', using 'from_rod' as auxiliary
        towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    }

    // Main method: Entry point of the program
    public static void main(String args[])
    {
        int N = 2;  // Number of disks
        
        // A, B and C are names of the three rods
        // Calling the recursive function to solve Tower of Hanoi puzzle for N disks
        towerOfHanoi(N, 'A', 'C', 'B');  // Move from rod 'A' to rod 'C' using rod 'B' as auxiliary
    }
}
