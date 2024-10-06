 public class CoinChange {
    public int coinChange(int[] coins, int amount) {
        // Initialize the dp array with amount + 1 (a value greater than any possible number of coins)
        int[] dp = new int[amount + 1];
        for (int i = 0; i <= amount; i++) {
            dp[i] = amount + 1;
        }
        
        // Base case: No coins are needed to make the amount 0
        dp[0] = 0;
        
        // Iterate through each amount from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Check each coin
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still amount + 1, it means it's not possible to form the amount
        return dp[amount] > amount ? -1 : dp[amount];
    }

    public static void main(String[] args) {
        CoinChange cc = new CoinChange();
        int[] coins = {1, 2, 5};
        int amount = 11;
        System.out.println(cc.coinChange(coins, amount));  // Output: 3
    }
}