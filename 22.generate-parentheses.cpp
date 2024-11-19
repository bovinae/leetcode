
#include <iostream>
#include <vector>

using namespace std;

// eg: n = 3, result = ["((()))","(()())","(())()","()(())","()()()"]
// interation: 
// (
// (( ()
// ((( (() ()(
// ((())) (()( (()) ()(( ()()
// (()()) (())() ()(()) ()()()

typedef struct A {
	string str;
	int count;

	A(string s, int c) {
		str = s;
		count = c;
	}
}A;

vector<string> generateParenthesis(int n) {
	vector<string> result;
	vector<A> tmp1;
	tmp1.emplace_back("(", 1);
	
	do {
		vector<A> tmp2;
		for (size_t i = 0; i < tmp1.size(); i++)
		{
			if (2 * n - tmp1[i].str.size() == tmp1[i].count) {
				for (size_t j = 0; j < tmp1[i].count; j++)
				{
					tmp1[i].str.append(")");
				}
				result.push_back(tmp1[i].str);
				continue;
			}

			if (tmp1[i].count == 0) {
				tmp2.emplace_back(tmp1[i].str + "(", tmp1[i].count + 1);
				continue;
			}

			tmp2.emplace_back(tmp1[i].str + "(", tmp1[i].count + 1);
			tmp2.emplace_back(tmp1[i].str + ")", tmp1[i].count - 1);
		}
		tmp1 = tmp2;
	} while (tmp1.size() > 0);

	return result;
}

int main()
{
	auto result = generateParenthesis(3);
	for (auto& i : result)
	{
		cout << i << "\t";
	}
	cout << endl;
}
