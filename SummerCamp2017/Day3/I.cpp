#include <bits/stdc++.h>
using namespace std;

int const maxN = 2 * 7e4 + 10;

typedef pair <int, int> pii; // map of (user_id, category_id)

int differentPairs;

map <pii, int> mapPairs;

struct nodeInSet
{
	int time, id;

	nodeInSet (int time, int id) : time(time), id(id) {}
};

bool operator < (nodeInSet A, nodeInSet B)
{
	return (A.time < B.time) || (A.time == B.time && A.id < B.id);
}

set <nodeInSet> interestSet [maxN], eventsSet [maxN];

struct interest
{
	int user_id;
	int category_id;
	int create_time;
	int heuristic_ctr;

} I [maxN];

struct events
{
	int user_id;
	int category_id; 
	int adv_id;
	int show_time;
	int click_flag;

} E [maxN];

struct ansStr
{
	int user_id;
	int category_id;
	int create_time;
	int heuristic_ctr;
	int adv_id;
	int show_time;
	int click_flag;

	ansStr (int user_id, int category_id, int create_time, int heuristic_ctr, int adv_id, int show_time, int click_flag) : user_id(user_id), category_id(category_id), create_time(create_time), heuristic_ctr(heuristic_ctr), adv_id(adv_id), show_time(show_time), click_flag(click_flag) {}
};

bool operator < (ansStr A, ansStr B)
{
	if (A.heuristic_ctr != B.heuristic_ctr)
		return (A.heuristic_ctr < B.heuristic_ctr);

	if (A.user_id != B.user_id)
		return (A.user_id < B.user_id);

	if (A.category_id != B.category_id)
		return (A.category_id < B.category_id);

	if (A.create_time != B.create_time)
		return (A.create_time < B.create_time);

	if (A.adv_id != B.adv_id)
		return (A.adv_id < B.adv_id);

	if (A.show_time != B.show_time)
		return (A.show_time < B.show_time);

	return true;
}

vector <ansStr> ans;

void solve ()
{
	for (int idEvent = 1; idEvent <= differentPairs; idEvent++)
	{
		while (!eventsSet[idEvent].empty() && !interestSet[idEvent].empty())
		{
			set <nodeInSet> :: iterator it;

			int show_time = eventsSet[idEvent].begin()->time;
			int id = eventsSet[idEvent].begin()->id;

			it = interestSet[idEvent].lower_bound (nodeInSet (show_time, -1));

			if (it == interestSet[idEvent].end())
				it--;

			if (it->time >= show_time)
			{
				if (it == interestSet[idEvent].begin())
				{
					eventsSet[idEvent].erase (eventsSet[idEvent].begin());
					continue;	
				}

				it--;
			}

			int create_time = it->time;
			int ID = it->id;

			ans.push_back (ansStr (I[ID].user_id, I[ID].category_id, I[ID].create_time, I[ID].heuristic_ctr, E[id].adv_id, E[id].show_time, E[id].click_flag));

			eventsSet[idEvent].erase (eventsSet[idEvent].begin());
		}
	}

	sort (ans.begin(), ans.end());
}

int main ()
{
	cin.sync_with_stdio (false);

	int interest_count;
	int events_count;

	cin >> interest_count >> events_count;

	for (int i = 1; i <= interest_count; i++)
	{
		int user_id;
		int category_id;
		int create_time;
		int heuristic_ctr;

		cin >> user_id >> category_id >> create_time >> heuristic_ctr;

		if (!mapPairs [pii (user_id, category_id)])
			mapPairs [pii (user_id, category_id)] = ++differentPairs;

		int id = mapPairs [pii (user_id, category_id)];

		interestSet[id].insert (nodeInSet (create_time, i));

		I[i].user_id = user_id;
		I[i].category_id = category_id;
		I[i].create_time = create_time;
		I[i].heuristic_ctr = heuristic_ctr;

	}

	for (int i = 1; i <= events_count; i++)
	{
		int user_id;
		int category_id; 
		int adv_id;
		int show_time;
		int click_flag;

		cin >> user_id >> category_id >> adv_id >> show_time >> click_flag;

		if (!mapPairs [pii (user_id, category_id)])
			mapPairs [pii (user_id, category_id)] = ++differentPairs;

		int id = mapPairs [pii (user_id, category_id)];

		eventsSet[id].insert (nodeInSet (show_time, i));

		E[i].user_id = user_id;
		E[i].category_id = category_id;
		E[i].adv_id = adv_id;
		E[i].show_time = show_time;
		E[i].click_flag = click_flag;

	}

	solve();

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].user_id << " " << ans[i].category_id << " " << ans[i].create_time << " " << ans[i].heuristic_ctr << " " << ans[i].adv_id << " " << ans[i].show_time << " " << ans[i].click_flag << '\n';

	return 0;
}