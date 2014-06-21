#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

bool check_possible(vector<set<vector<set<int>>>> const &constraints) {
	if (constraints.empty()) {
		return true;
	}

	for (auto choice = constraints.front().begin(); choice != constraints.front().end(); ++choice) {
		vector<set<vector<set<int>>>> intersected_constraints;
		for (auto cascade = ++constraints.begin(); cascade != constraints.end(); ++cascade) {
			set<vector<set<int>>> intersected_round;
			for (auto possibility = cascade->begin(); possibility != cascade->end(); ++possibility) {
				vector<set<int>> intersected_possibility;
				for (size_t elem_idx = 0; elem_idx < possibility->size(); ++elem_idx) {
					set<int> intersected;
					set_intersection(
							(*choice)[elem_idx].begin(), (*choice)[elem_idx].end(),
							(*possibility)[elem_idx].begin(), (*possibility)[elem_idx].end(),
							inserter(intersected, intersected.begin()));
					if (intersected.empty()) {
						break;
					}
					intersected_possibility.push_back(intersected);
				}
				if (intersected_possibility.size() == possibility->size()) {
					intersected_round.insert(intersected_possibility);
				}
			}
			if (intersected_round.empty()) {
				break;
			}
			intersected_constraints.push_back(intersected_round);
		}
		if (intersected_constraints.size() == constraints.size() - 1) {
			if (check_possible(intersected_constraints)) {
				return true;
			}
		}
	}

	return false;
}

int main(int argc, char const *argv[]) {
	int test_case_count;
	cin >> test_case_count;
	for (int test_case_idx = 0; test_case_idx < test_case_count; ++test_case_idx) {
		int n, q, k;
		cin >> n >> k >> q;
		vector<vector<int>> guesses;
		vector<int> scores;
		for (int round_idx = 0; round_idx < q; ++round_idx) {
			guesses.push_back(vector<int>());
			for (int elem_idx = 0; elem_idx < k; ++elem_idx) {
				int elem;
				cin >> elem;
				guesses.back().push_back(elem);
			}
			int score;
			cin >> score;
			scores.push_back(score);
		}

		set<int> ALL;
		for (int n_idx = 0; n_idx < n; ++n_idx) {
			ALL.insert(n_idx);
		}

		vector<set<vector<set<int>>>> constraints;
		for (int round_idx = 0; round_idx < q; ++round_idx) {
			constraints.push_back(set<vector<set<int>>>());
			vector<int> const &guess = guesses[round_idx];
			int const &score = scores[round_idx];

			vector<bool> filter;
			for (int i = 0; i < k - score; ++i) {
				filter.push_back(false);
			}
			for (int i = 0; i < score; ++i) {
				filter.push_back(true);
			}

			do {
				vector<set<int>> constraint;
				for (int elem_idx = 0; elem_idx < k; ++elem_idx) {
					if (filter[elem_idx]) {
						set<int> possibilities = { guess[elem_idx] };
						constraint.push_back(possibilities);
					} else {
						set<int> possibilities(ALL);
						possibilities.erase(guess[elem_idx]);
						constraint.push_back(possibilities);
					}
				}
				constraints.back().insert(constraint);
			} while (next_permutation(filter.begin(), filter.end()));
		}

		bool possible = check_possible(constraints);
		if (possible) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}

	}

	return 0;
}
