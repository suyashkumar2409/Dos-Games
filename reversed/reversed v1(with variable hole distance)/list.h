#include"wall.h"
struct list{
	wall info;
	list* link;
};
class pointer{
	private:
		list* last,*first,*current;
		int count;
	public:
		void initialise();
		pointer();
		wall* returnwall(int);
		void newwall(wall);
		void deletewall();
		int returncount();
		~pointer();
};
