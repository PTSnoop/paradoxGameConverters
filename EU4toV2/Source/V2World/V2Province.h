/*Copyright (c) 2014 The Paradox Game Converters Project

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



#ifndef V2PROVINCE_H_
#define V2PROVINCE_H_



#include "../Configuration.h"
#include "../EU4World/EU4World.h"
#include "../EU4World/EU4Country.h"

class V2Pop;
class V2Factory;



struct V2Demographic
{
	string								culture;
	string								religion;
	double								ratio;
	EU4Province*						oldProvince;
	EU4Country*							oldCountry;
};


class V2Province
{
	public:
		V2Province(string _filename);
		void output() const;
		void convertFromOldProvince(const EU4Province* oldProvince);
		void determineColonial();
		void addCore(string);
		void addOldPop(const V2Pop*);
		void doCreatePops(bool isStateCapital, int statePopulation);
		void sortPops();

		int				getTotalPopulation() const;
		vector<V2Pop*>	getPops(string type) const;
		int				getSoldierPopForArmy(bool force = false);
		pair<int, int>	getAvailableSoldierCapacity() const;
		string			getRegimentName(RegimentCategory rc);
		bool				hasCulture(string culture, float percentOfPopulation) const;
		
		void				clearCores()									{ cores.clear(); }
		void				setCoastal(bool _coastal)					{ coastal = _coastal; }
		void				setName(string _name)						{ name = _name; }
		void				setOwner(string _owner)						{ owner = _owner; }
		void				setLandConnection(bool _connection)		{ landConnection = _connection; }
		void				setSameContinent(bool _same)				{ sameContinent = _same; }
		void				addPopDemographic(V2Demographic d)		{ demographics.push_back(d); }
		void				setFortLevel(int level)						{ fortLevel = level; }
		void				setNavalBaseLevel(int level)				{ navalBaseLevel = level; }
		void				setRailLevel(int level)						{ railLevel = level; }
		void				addFactory(const V2Factory* factory)	{ factories.push_back(factory); }

		const EU4Province*	getSrcProvince()		const { return srcProvince; }
		int						getOldPopulation()	const	{ return oldPopulation; }
		bool						wasInfidelConquest()	const { return originallyInfidel; }
		bool						wasColony()				const { return wasColonised; }
		bool						isColonial()			const { return colonial != 0; }
		string					getRgoType()			const { return rgoType; }
		string					getOwner()				const { return owner; }
		int						getNum()					const { return num; }
		string					getName()				const { return name; }
		bool						isCoastal()				const { return coastal; }
		bool						hasNavalBase()			const { return (navalBaseLevel > 0); }
		bool						hasLandConnection()	const { return landConnection; }
	private:
		void outputPops(FILE*) const;
		void outputUnits(FILE*) const;
		void createPops(const V2Demographic& d, bool isStateCapital, int statePopulation);
		void combinePops();
		bool growSoldierPop(V2Pop* pop);

		const EU4Province*			srcProvince;
		
		string							filename;
		bool								coastal;
		int								num;
		string							name;
		string							owner;
		vector<string>					cores;
		int								colonyLevel;
		int								colonial;
		bool								wasColonised;
		bool								landConnection;
		bool								sameContinent;
		bool								originallyInfidel;
		int								oldPopulation;
		vector<V2Demographic>		demographics;
		vector<const V2Pop*>			oldPops;
		vector<V2Pop*>					pops;
		string							rgoType;
		string							terrain;
		int								lifeRating;
		bool								slaveState;
		int								unitNameCount[num_reg_categories];
		int								fortLevel;
		int								navalBaseLevel;
		int								railLevel;
		vector<const V2Factory*>	factories;
};



#endif // V2PROVINCE_H_