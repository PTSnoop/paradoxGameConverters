#ifndef CK2TITLE_H_
#define CK2TITLE_H_


#include <vector>
#include <map>
using namespace std;


class Object;
class CK2Character;
class CK2History;

class CK2Title
{
	public:
		CK2Title(Object*, map<int, CK2Character*>&);

		void						addLiege(CK2Title*);
		void						addToHRE();
		void						determineHeir(map<int, CK2Character*>&);
		void						setHeir(CK2Character*);

		string					getTitleString()		const { return titleString; };
		CK2Character*			getHolder()				const { return holder; };
		CK2Character*			getHeir()				const { return heir; };
		string					getSuccessionLaw()	const { return successionLaw; };
		vector<CK2History*>	getHistory()			const { return history; };
		string					getLiegeString()		const { return liegeString; };
		CK2Title*				getLiege()				const { return liege; };
		bool						isIndependent()		const { return independent; };
		bool						isInHRE()				const { return inHRE; };
	private:
		void								addVassal(CK2Title*);
		CK2Character*					getFeudalElectiveHeir(map<int, CK2Character*>&);
		CK2Character*					getTurkishSuccessionHeir();

		string							titleString;
		CK2Character*					holder;
		CK2Character*					heir;
		string							successionLaw;
		string							genderLaw;
		vector< pair<int, int> >	nominees;		// id, votes
		vector<CK2History*>			history;
		string							liegeString;
		CK2Title*						liege;
		vector<CK2Title*>				vassals;

		bool								independent;
		bool								inHRE;
};



#endif // CK2TITLE_H_