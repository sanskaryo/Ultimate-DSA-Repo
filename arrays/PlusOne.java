/**
 * Plus One
 * ========
 * 
 * Problem: Given a large integer represented as an integer array digits, where each 
 * digits[i] is the ith digit of the integer. The digits are ordered from most 
 * significant to least significant in left-to-right order. Increment the large 
 * integer by one and return the resulting array of digits.
 * 
 * Approach 1 - Reverse Iteration with Carry (Optimized):
 * - Start from the last digit (least significant)
 * - Add 1 to the last digit
 * - Handle carry propagation: if digit becomes 10, set it to 0 and carry 1
 * - Continue until no carry or we've processed all digits
 * - If carry remains after processing all digits, insert 1 at the beginning
 * 
 * Approach 2 - Explicit Carry:
 * - Use carry variable to track overflow
 * - Process digits from right to left
 * - More verbose but easier to understand
 * 
 * Time Complexity: O(n) where n is the number of digits
 * Space Complexity: O(1) for in-place, O(n) if all digits are 9
 */

import java.util.Arrays;

public class PlusOne {
    
    /**
     * Add one to the number using optimized carry propagation.
     * 
     * @param digits Array of integers representing a large number
     * @return Array of integers representing the incremented number
     * 
     * Example:
     *   Input: digits = [1, 2, 3]
     *   Output: [1, 2, 4]
     *   
     *   Input: digits = [9, 9, 9]
     *   Output: [1, 0, 0, 0]
     */
    public static int[] plusOneOptimized(int[] digits) {
        int n = digits.length;
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        int[] result = new int[n + 1];
        result[0] = 1;
        return result;
    }
    
    /**
     * Add one using explicit carry variable.
     * More verbose but easier to understand.
     */
    public static int[] plusOneWithCarry(int[] digits) {
        int carry = 1;
        int n = digits.length;
        int[] result = Arrays.copyOf(digits, n);
        
        for (int i = n - 1; i >= 0; i--) {
            int total = result[i] + carry;
            result[i] = total % 10;
            carry = total / 10;
            
            if (carry == 0) {
                break;
            }
        }
        
        if (carry > 0) {
            int[] newResult = new int[n + 1];
            newResult[0] = carry;
            System.arraycopy(result, 0, newResult, 1, n);
            return newResult;
        }
        
        return result;
    }
    
    /**
     * Recursive approach for educational purposes.
     */
    public static int[] plusOneRecursive(int[] digits) {
        return plusOneRecursiveHelper(digits, digits.length - 1);
    }
    
    private static int[] plusOneRecursiveHelper(int[] digits, int index) {
        if (index < 0) {
            int[] result = new int[digits.length + 1];
            result[0] = 1;
            System.arraycopy(digits, 0, result, 1, digits.length);
            return result;
        }
        
        if (digits[index] < 9) {
            digits[index]++;
            return digits;
        }
        
        digits[index] = 0;
        return plusOneRecursiveHelper(digits, index - 1);
    }
    
    public static void printArray(int[] arr, String label) {
        System.out.print(label + ": [");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
    
    public static boolean arraysEqual(int[] arr1, int[] arr2) {
        return Arrays.equals(arr1, arr2);
    }
    
    public static void runTestCases() {
        System.out.println("=== Plus One Test Results (Java) ===\n");
        
        int[][] inputs = {
            {1, 2, 3},
            {4, 3, 2, 1},
            {9},
            {9, 9, 9},
            {1, 9, 9},
            {0},
            {8, 9, 9, 9},
            {1, 2, 9}
        };
        
        int[][] expected = {
            {1, 2, 4},
            {4, 3, 2, 2},
            {1, 0},
            {1, 0, 0, 0},
            {2, 0, 0},
            {1},
            {9, 0, 0, 0},
            {1, 3, 0}
        };
        
        String[] descriptions = {
            "Basic increment without carry",
            "Increment without carry propagation",
            "Single digit 9 (edge case)",
            "All digits are 9 (maximum carry)",
            "Partial 9s requiring carry",
            "Edge case: incrementing zero",
            "Multiple 9s at the end",
            "Single 9 at the end"
        };
        
        for (int i = 0; i < inputs.length; i++) {
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            
            printArray(inputs[i], "Input   ");
            printArray(expected[i], "Expected");
            
            int[] resultOptimized = plusOneOptimized(Arrays.copyOf(inputs[i], inputs[i].length));
            int[] resultCarry = plusOneWithCarry(Arrays.copyOf(inputs[i], inputs[i].length));
            int[] resultRecursive = plusOneRecursive(Arrays.copyOf(inputs[i], inputs[i].length));
            
            printArray(resultOptimized, "Optimized ");
            printArray(resultCarry, "Carry     ");
            printArray(resultRecursive, "Recursive ");
            
            boolean optimizedCorrect = arraysEqual(resultOptimized, expected[i]);
            boolean carryCorrect = arraysEqual(resultCarry, expected[i]);
            boolean recursiveCorrect = arraysEqual(resultRecursive, expected[i]);
            
            System.out.println("✅ Optimized:  " + (optimizedCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Carry:      " + (carryCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Recursive:  " + (recursiveCorrect ? "PASSED" : "FAILED"));
            System.out.println("-".repeat(70));
        }
    }
    
    public static void main(String[] args) {
        runTestCases();
        
        System.out.println("\n=== Interactive Example ===");
        int[] sampleDigits = {1, 9, 9};
        System.out.print("Adding 1 to number represented by: ");
        printArray(sampleDigits, "");
        
        System.out.println("\nStep-by-step process (Optimized approach):");
        int[] digits = Arrays.copyOf(sampleDigits, sampleDigits.length);
        int n = digits.length;
        
        for (int i = n - 1; i >= 0; i--) {
            System.out.println("\nStep " + (n - i) + ": Checking digit at index " + i 
                + " (value: " + digits[i] + ")");
            
            if (digits[i] < 9) {
                System.out.println("  ✅ Digit " + digits[i] + " < 9, increment it to " 
                    + (digits[i] + 1));
                digits[i]++;
                System.out.print("  Final result: ");
                printArray(digits, "");
                break;
            } else {
                System.out.println("  ⚠️  Digit is 9, set to 0 and carry over");
                digits[i] = 0;
                System.out.print("  Current state: ");
                printArray(digits, "");
                System.out.println(" (carry continues)");
            }
        }
        
        System.out.println("\n=== Performance Analysis ===");
        System.out.println("For an array of n digits:");
        System.out.println("• Optimized Approach:  O(n) time, O(1) space* - Best for most cases");
        System.out.println("• Carry Approach:      O(n) time, O(n) space - More explicit");
        System.out.println("• Recursive Approach:  O(n) time, O(n) space - Educational");
        System.out.println("\n*O(1) when modifying in-place, O(n) when all digits are 9");
    }
}
