/*Napisz procedurê, która zadany podwektor napisów typu std::string,
reprezentuj¹cy kolejne wpisy w logu pewnej aplikacji, posortuje zgodnie z porz¹dkiem leksykograficznym
dzia³aj¹cym na pierwszym wystêpuj¹cym haœle (ujêtym w kwadratowe nawiasy) w napisie. Napisy bez hase³
s¹ równowa¿ne miêdzy sob¹ i wiêksze od napisów z has³ami, a ró¿ne napisy z takim samym pierwszym has³em
s¹ równowa¿ne. Nale¿y zadbaæ o to, ¿eby nie zmieniæ wzglêdnej kolejnoœci w grupach równowa¿nych napisów.
Nie wolno u¿ywaæ pêtli ani rekursji, nale¿y funkcjê zaimplementowaæ przy pomocy algorytmów z biblioteki
standardowej (podpowiedŸ: stable_sort, find oraz lexicographical_compare).*/

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>

bool compare( std::string x, std::string y )
{
    std::string::iterator x1, x2, y1, y2;

    x1 = std::find( std::begin(x), std::end(x), '[' );
    x2 = std::find( std::begin(x), std::end(x), ']' );
    y1 = std::find( std::begin(y), std::end(y), '[' );
    y2 = std::find( std::begin(y), std::end(y), ']' );

    if( x1 == std::end(x) && y1 == std::end(y) )
    {
        x1 = std::begin(x);
        y1 = std::begin(y);
    }
    else if( x1 == std::end(x) && y1 != std::end(y) )
    {
        return false;
    }
    else if( x1 != std::end(x) && y1 == std::end(y) )
    {
        return true;
    }

    return std::lexicographical_compare( x1, x2, y1, y2 );
}

void SortujPoHaslach( std::vector< std::string >::iterator p, std::vector< std::string >::iterator k ) {
    std::stable_sort( p, k, [&]( std::string x, std::string y )->bool{ std::string::iterator x1 = std::find( std::begin(x), std::end(x), '[' ), x2 = std::find( std::begin(x), std::end(x), ']' ), y1 = std::find( std::begin(y), std::end(y), '[' ), y2 = std::find( std::begin(y), std::end(y), ']' ); if( x1 == std::end(x) && y1 == std::end(y) ) { x1 = std::begin(x); y1 = std::begin(y); } else if( x1 == std::end(x) && y1 != std::end(y) ) { return false; } else if( x1 != std::end(x) && y1 == std::end(y) ) { return true; } return std::lexicographical_compare( x1, x2, y1, y2 ); } );
    //std::stable_sort( p, k, compare );
}

void test_SortujPoHaslach(void) {
    std::vector<std::string> d {"O 13 uruchomienie aplikacji",
                                "O 14 proba logowania haslem [madrehaslo] zakonczona powodzeniem",
                                "O 15 proba logowania haslem [glupiehaslo] zakonczona niepowodzeniem",
                                "O 15.30 restart aplikacji",
                                "Uzytkownik zmienil [madrehaslo] na [innehaslo] o 16",
                                "O 17 odmowa zmiany hasla na [aaaaaa] z powodu niedostateczego skomplikowania",
                                "O 18 chyba bledna proba zmiany hasla na puste []"
                                };

    std::vector<std::string> ds{"O 18 chyba bledna proba zmiany hasla na puste []",
                                "O 17 odmowa zmiany hasla na [aaaaaa] z powodu niedostateczego skomplikowania",
                                "O 15 proba logowania haslem [glupiehaslo] zakonczona niepowodzeniem",
                                "O 14 proba logowania haslem [madrehaslo] zakonczona powodzeniem",
                                "Uzytkownik zmienil [madrehaslo] na [innehaslo] o 16",
                                "O 13 uruchomienie aplikacji",
                                "O 15.30 restart aplikacji"
                                };

    SortujPoHaslach(std::begin(d),std::end(d));

    assert(d==ds);


    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main(void)
{
    test_SortujPoHaslach();

    std::cin.get();

    return 0;
}

