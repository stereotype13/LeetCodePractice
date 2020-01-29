/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

	The town judge trusts nobody.
	Everybody (except for the town judge) trusts the town judge.
	There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.



Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3



Note:

	1 <= N <= 1000
	trust.length <= 10000
	trust[i] are all different
	trust[i][0] != trust[i][1]
	1 <= trust[i][0], trust[i][1] <= N


*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;



class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {

		if (trust.empty())
			return N;

		vector<int> numberOfPeopleTrustingThisPerson(N, 0);
		vector<int> numberOfPeopleThisPersonTrusts(N, 0);

		for (const auto& trustRelationship : trust) {
			numberOfPeopleTrustingThisPerson[trustRelationship[1] - 1]++;
			numberOfPeopleThisPersonTrusts[trustRelationship[0] - 1]++;
			
		}

		
		for (int i = 0; i < (int)numberOfPeopleTrustingThisPerson.size(); ++i) {
			if (numberOfPeopleTrustingThisPerson[i] == N - 1 && numberOfPeopleThisPersonTrusts[i] == 0) 
				return i + 1;	
		}

		return -1;
	}
};

int main(int argc, const char* argv[]) {
	Solution solution;

	vector<vector<int>> trust1{ {1, 2} };
	cout << solution.findJudge(2, trust1) << endl; //2

	vector<vector<int>> trust2{{1, 3}, {2, 3}};
	cout << solution.findJudge(3, trust2) << endl; //3

	vector<vector<int>> trust3{{1, 3}, {2, 3}, {3, 1}};
	cout << solution.findJudge(3, trust3) << endl; //-1

	vector<vector<int>> trust4{ {1, 2}, {2, 3} };
	cout << solution.findJudge(3, trust4) << endl; //-1

	vector<vector<int>> trust5{{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
	cout << solution.findJudge(4, trust5) << endl; //3

	cin.get();
	return 0;
}