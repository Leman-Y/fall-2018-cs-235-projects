

//#include "LinkedSet.h"
//#include "PlayList.h"
//#include "PlayList.cpp"
//#include "Song.h"
//#include "Song.cpp"
//#include "Node.h"
//#include "Node.cpp"

#include "PlayList.h"
#include "Song.h"
//#include "Song.cpp" You had to include "Song.cpp", because you did not include at the bottom of Song.h

#include "PlayList.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    

    // Test PlayList

    

    std::cout << "**** Instantiating Song objects **** \n";

    

    Song song1("song1","author1","album1");

    Song song2("song2", "author2", "album2");

    Song song3("song3", "author3", "album3");

    Song song4("song4", "author4", "album4");

    Song song5("song5", "author5", "album5");

    

    

    std::cout << "\n\n**** Testing PlayList class **** \n";

    std::cout << "\nAdd songs to PlayList, check adding to end of chain and no duplicates allowed: \n";

    

    PlayList playlist1(song1);

    playlist1.add(song2);

    playlist1.add(song3);

    playlist1.add(song1);

    playlist1.add(song2);

    playlist1.add(song3);


    std::vector<Song> song_vector = playlist1.toVector();


    playlist1.displayPlayList();
	
//cout<<"getPointerToLastNode() "<<(playlist1.getPointerToLastNode())->getItem().getTitle()<<endl;

    

    std::cout << "\n\nAdd remaining songs\n";

    playlist1.add(song4);

    playlist1.add(song5);

    playlist1.displayPlayList(); 
	
//cout<<"getPointerToLastNode()"<<(playlist1.getPointerToLastNode())->getItem().getTitle()<<endl;

    

   std::cout << "\n\nCheck that linked chain corresponds in LinkedSet(true)\n";

    std::cout << playlist1.contains(song3); // (true) 

    


    std::cout << "\n\nTest removing songs from PlayList, check that order is preserved\n";

    

    std::cout << "\nRemove from the middle\n";

    playlist1.remove(song3);

    playlist1.displayPlayList();   

    

    

    std::cout << "\nRemove first song\n";

    playlist1.remove(song1);

    playlist1.displayPlayList();  

    

    std::cout << "\nRemove last song\n";

    playlist1.remove(song5);

    playlist1.displayPlayList();   

    

    std::cout << "\n\nCheck that linked chain corresponds in LinkedSet after removal (false)\n";

    std::cout << playlist1.contains(song3);    //(false) 



    std::cout << "\n\nTest copy constructor\n";

    

    PlayList playlist2 = playlist1;

    std::cout << "\nPrinting playlist2 \n";

    playlist2.displayPlayList();  

//cout<<"getPointerToLastNode() "<<(playlist2.getPointerToLastNode())->getItem().getTitle()<<endl;

    std::cout << "\n\nCheck that copied chain corresponds in LinkedSet\n";

    std::cout << playlist2.contains(song2) << std::endl;    // (true)

    std::cout << playlist2.contains(song3) << std::endl;     //(false)


//cout<<"getPointerToLastNode()"<<(playlist1.getPointerToLastNode())->getItem().getTitle()<<endl;


    std::cout << "\nAdd song to copied playlist\n";

    playlist2.add(song1);

    playlist2.displayPlayList();   

    
//cout<<"getPointerToLastNode()"<<(playlist2.getPointerToLastNode())->getItem().getTitle()<<endl;

    std::cout << "\nRemove last song from copied playlist\n";

    playlist2.remove(song1);

    playlist2.displayPlayList();  

    

    std::cout << "\nRemove first song from copied playlist\n";

    playlist2.remove(song2);

    playlist2.displayPlayList();   

    
//	cout<<"getPointerToLastNode()"<<(playlist2.getPointerToLastNode())->getItem().getTitle()<<endl;
    

    return 0;

}

/*
Output
  Add song to copied playlist
  * Title: song2* Author: author2* Album: album2 *
  * Title: song4* Author: author4* Album: album4 *
  * Title: song1* Author: author1* Album: album1 *
  End of PlayList
Expected
  Add song to copied playlist
  * Title: song2* Author: author2* Album: album2 *
  * Title: song4* Author: author4* Album: album4 *
  * Title: song1* Author: author1* Album: album1 *
  End of playlist

*/





































