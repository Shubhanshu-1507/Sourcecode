class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int totalSkill = skill[0] + skill[n-1];  // skill sum of the first and last player
        long long totalChemistry = 0;

        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1;  // If any pair doesn't match the required skill sum, return -1
            }
            totalChemistry += (long long)skill[i] * skill[n - i - 1];  // Add the product to chemistry
        }

        return totalChemistry;
    }
};
