/*
PROBLEM ASKED IN DELTAX FOR ASSOCIATE PRODUCT ENGINEER FOR THE YEAR 2024 - Contributed by Sourasish Mondal

In the mystical land of Arithma, numbers and operators are not just symbols on paper-they are alive with magic. The land's greatest mathematicians have discovered a powerful spell that allows them to explore all possible outcomes of a given numerical expression by grouping the numbers and operators in different ways. Every combination reveals a new possibility.
As one of Arithma's wizards, your task is to decipher these magical expressions by breaking them down into all conceivable groupings and calculating the outcomes. Each unique configuration of parentheses leads to a new result.
Your challenge is to return the sum of all possible outcomes for a given expression.
Note: The divison of 2 numbers should be considered as a whole number. E.g. 5/2 should return 2 instead of 2.5

Example 1:
Input: "2-1-1"
• Output: 2
• Explanation: Sum of all possible outcomes is 2 ((2 - 1) - 1) = theta (2 - (1 - 1)) = 2

Example 2:
Input: "2*3-4*5"
Output: -58
Explanation: Sum of all possible outcomes is -58 (2^ * (3 - (4 * 5)) )=-34 ((2 * 3) - (4 * 5)) = - 14 ((2(3 * 4)) * 5) = - 10 (2((3 - 4) * 5)) = - 10 (((2 * 3) * 4) * 5) = 16
Constraints:
• 1 <= expression.length <= 20
• Expression consists of digits and the operator +,-, / and *.
• All the integer values in the input expression are in the range [0, 99]

Sample Input: 2-1-1
Sample Output: 2
Sample Input: 2*3-4*5
Sample Output: -58

*/

import java.util.ArrayList;
import java.util.List;

public class DeltaX_EvaluateExpression {
    public static List<Integer> evaluateExpression(String expression) {
        if (expression.matches("\\d+")) {
            List<Integer> result = new ArrayList<>();
            result.add(Integer.parseInt(expression));
            return result;
        }
        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < expression.length(); i++) {
            if ("+-*/".indexOf(expression.charAt(i)) != -1) {
                String left = expression.substring(0, i);
                String right = expression.substring(i + 1);
                List<Integer> leftResults = evaluateExpression(left);
                List<Integer> rightResults = evaluateExpression(right);
                for (int leftValue : leftResults) {
                    for (int rightValue : rightResults) {
                        switch (expression.charAt(i)) {
                            case '+':
                                results.add(leftValue + rightValue);
                                break;
                            case '-':
                                results.add(leftValue - rightValue);
                                break;
                            case '*':
                                results.add(leftValue * rightValue);
                                break;
                            case '/':
                                if (rightValue != 0) {
                                    results.add(leftValue / rightValue);
                                }
                                break;
                        }
                    }
                }
            }
        }
        return results;
    }
    public static int sumOfOutcomes(String expression) {
        List<Integer> outcomes = evaluateExpression(expression);
        return outcomes.stream().mapToInt(Integer::intValue).sum();
    }
    public static void main(String[] args) {
        String input1 = "2-1-1";
        String input2 = "2*3-4*5";
        System.out.println(sumOfOutcomes(input1));  // Output: 2
        System.out.println(sumOfOutcomes(input2));  // Output: -58
    }
}
