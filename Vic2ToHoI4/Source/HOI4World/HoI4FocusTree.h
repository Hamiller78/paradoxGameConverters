/*Copyright (c) 2017 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#ifndef HOI4_FOCUS_TREE
#define HOI4_FOCUS_TREE

#include "HoI4World.h"
#include "HoI4Events.h"
#include <string>
#include <vector>
using namespace std;



class HoI4Country;
class HoI4Focus;
class HoI4Events;



class HoI4FocusTree
{
	public:
		HoI4FocusTree();
		explicit HoI4FocusTree(const HoI4Country* country);

		HoI4FocusTree* makeCustomizedCopy(const HoI4Country* country) const;
		void setNextFreeColumn(int newFreeColumn) { nextFreeColumn = newFreeColumn; };

		void addGenericFocusTree(const set<string>& majorIdeologies);

		void addDemocracyNationalFocuses(const HoI4Country* Home, const vector<const HoI4Country*>& CountriesToContain);
		void addAbsolutistEmpireNationalFocuses(const HoI4Country* country, const vector<HoI4Country*>& targetColonies, const vector<HoI4Country*>& annexationTargets);
		void addCommunistCoupBranch(const HoI4Country* Home, const vector<HoI4Country*>& coupTargets);
		void addCommunistWarBranch(const HoI4Country* Home, const vector<HoI4Country*>& warTargets, HoI4Events* events);
		void addFascistAnnexationBranch(const HoI4Country* Home, const vector<const HoI4Country*>& annexationTargets, HoI4Events* events);
		void addFascistSudetenBranch(const HoI4Country* Home, const vector<const HoI4Country*>& sudetenTargets, const vector<vector<int>>& demandedStates, const HoI4World* world);
		void addGPWarBranch(const HoI4Country* Home, const vector<HoI4Country*>& newAllies, const vector<const HoI4Country*>& GCTargets, const string& ideology, HoI4Events* events);

		void output(const string& filename) const;

		void addFocus(HoI4Focus* newFocus) { focuses.push_back(newFocus); }

	private:
		HoI4FocusTree(const HoI4FocusTree&) = delete;
		HoI4FocusTree& operator=(const HoI4FocusTree&) = delete;

		int calculateNumCollectovistIdeologies(const set<string>& majorIdeologies);
		void determineMutualExclusions(const set<string>& majorIdeologies);
		void addFascistGenericFocuses();
		void addCommunistGenericFocuses();
		void addAbsolutistGenericFocuses();
		void addRadicalGenericFocuses();

		string srcCountryTag;
		string dstCountryTag;
		vector<HoI4Focus*> focuses;
		int nextFreeColumn;

		string fascistMutualExlusions;
		string communistMutualExclusions;
		string absolutistMutualExlusions;
		string radicalMutualExclusions;
};



#endif // HOI4_FOCUS_TREE