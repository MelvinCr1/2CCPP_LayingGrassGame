#include <cctype>

#include "Tile.hpp"


// Fonction pour renvoyer la forme de la tuile en fonction de son type
std::vector<std::vector<char>> Tile::Form(char refChar) const {
    switch(type) {
        case 1:
            return form1(refChar);
        case 2:
            return form2(refChar);
        case 3:
            return form3(refChar);
        case 4:
            return form4(refChar);
        case 5:
            return form5(refChar);
        case 6:
            return form6(refChar);
        case 7:
            return form7(refChar);
        case 8:
            return form8(refChar);
        case 9:
            return form9(refChar);
        case 10:
            return form10(refChar);
        case 11:
            return form11(refChar);
        case 12:
            return form12(refChar);
        case 13:
            return form13(refChar);
        case 14:
            return form14(refChar);
        case 15:
            return form15(refChar);
        case 16:
            return form16(refChar);
        case 17:
            return form17(refChar);
        case 18:
            return form18(refChar);
        case 19:
            return form19(refChar);
        case 20:
            return form20(refChar);
        case 21:
            return form21(refChar);
        case 22:
            return form22(refChar);
        case 23:
            return form23(refChar);
        case 24:
            return form24(refChar);
        case 25:
            return form25(refChar);
        case 26:
            return form26(refChar);
        case 27:
            return form27(refChar);
        case 28:
            return form28(refChar);
        case 29:
            return form29(refChar);
        case 30:
            return form30(refChar);
        case 31:
            return form31(refChar);
        case 32:
            return form32(refChar);
        case 33:
            return form33(refChar);
        case 34:
            return form34(refChar);
        case 35:
            return form35(refChar);
        case 36:
            return form36(refChar);
        case 37:
            return form37(refChar);
        case 38:
            return form38(refChar);
        case 39:
            return form39(refChar);
        case 40:
            return form40(refChar);
        case 41:
            return form41(refChar);
        case 42:
            return form42(refChar);
        case 43:
            return form43(refChar);
        case 44:
            return form44(refChar);
        case 45:
            return form45(refChar);
        case 46:
            return form46(refChar);
        case 47:
            return form47(refChar);
        case 48:
            return form48(refChar);
        case 49:
            return form49(refChar);
        case 50:
            return form50(refChar);
        case 51:
            return form51(refChar);
        case 52:
            return form52(refChar);
        case 53:
            return form53(refChar);
        case 54:
            return form54(refChar);
        case 55:
            return form55(refChar);
        case 56:
            return form56(refChar);
        case 57:
            return form57(refChar);
        case 58:
            return form58(refChar);
        case 59:
            return form59(refChar);
        case 60:
            return form60(refChar);
        case 61:
            return form61(refChar);
        case 62:
            return form62(refChar);
        case 63:
            return form63(refChar);
        case 64:
            return form64(refChar);
        case 65:
            return form65(refChar);
        case 66:
            return form66(refChar);
        case 67:
            return form67(refChar);
        case 68:
            return form68(refChar);
        case 69:
            return form69(refChar);
        case 70:
            return form70(refChar);
        case 71:
            return form71(refChar);
        case 72:
            return form72(refChar);
        case 73:
            return form73(refChar);
        case 74:
            return form74(refChar);
        case 75:
            return form75(refChar);
        case 76:
            return form76(refChar);
        case 77:
            return form77(refChar);
        case 78:
            return form78(refChar);
        case 79:
            return form79(refChar);
        case 80:
            return form80(refChar);
        case 81:
            return form81(refChar);
        case 82:
            return form82(refChar);
        case 83:
            return form83(refChar);
        case 84:
            return form84(refChar);
        case 85:
            return form85(refChar);
        case 86:
            return form86(refChar);
        case 87:
            return form87(refChar);
        case 88:
            return form88(refChar);
        case 89:
            return form89(refChar);
        case 90:
            return form90(refChar);
        case 91:
            return form91(refChar);
        case 92:
            return form92(refChar);
        case 93:
            return form93(refChar);
        case 94:
            return form94(refChar);
        case 95:
            return form95(refChar);
        case 96:
            return form96(refChar);
        default:
            return {};
    }
}

// Fonctions pour définir les motifs spécifiques à chaque forme de tuile
    std::vector<std::vector<char>> Tile::form1(char refChar) {
        return {
            {static_cast<char>(std::tolower(refChar)), '.', '.'},
            {refChar, refChar, refChar}
        };
    }

std::vector<std::vector<char>> Tile::form2(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', refChar, '.'},
        {refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form3(char refChar) {
    return {
        {'.', refChar, '.'},
        {refChar, static_cast<char>(std::tolower(refChar)), refChar},
        {'.', refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form4(char refChar) {
    return {
        {'.', '.', refChar},
        {refChar, static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, '.', '.'}
    };
}

std::vector<std::vector<char>> Tile::form5(char refChar) {
    return {
        {'.', refChar, '.'},
        {refChar, static_cast<char>(std::tolower(refChar)), refChar}
    };
}

std::vector<std::vector<char>> Tile::form6(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form7(char refChar) {
    return {
        {refChar, '.', refChar},
        {refChar, static_cast<char>(std::tolower(refChar)), refChar}
    };
}

std::vector<std::vector<char>> Tile::form8(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar , refChar}
    };
}

std::vector<std::vector<char>> Tile::form9(char refChar) {
    return {
        {'.', '.',  static_cast<char>(std::tolower(refChar))},
        {'.', refChar, refChar},
        {refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form10(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form11(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar))},
        {'.', refChar, refChar},
        {refChar, refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form12(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar},
    };
}

std::vector<std::vector<char>> Tile::form13(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, '.'},
        {refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form14(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {refChar, '.', '.'},
        {refChar, '.', '.'},
        {refChar, '.', '.'},
        {refChar, '.', '.'}
    };
}

std::vector<std::vector<char>> Tile::form15(char refChar) {
    return {
        {'.', '.', '.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', '.', '.', refChar, '.'},
        {'.', '.', '.', refChar, refChar},
        {'.', refChar, refChar, refChar, '.'},
        {refChar, refChar, '.', '.', '.'}
    };
}

std::vector<std::vector<char>> Tile::form16(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar))},
        {'.', refChar, refChar},
        {refChar, refChar, '.'},
        {refChar, '.', '.'}
    };
}

std::vector<std::vector<char>> Tile::form17(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar, refChar},
        {refChar, refChar, '.'},
    };
}

std::vector<std::vector<char>> Tile::form18(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar},
    };
}

std::vector<std::vector<char>> Tile::form19(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form20(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar, '.'},
        {refChar, refChar, '.'},
    };
}

std::vector<std::vector<char>> Tile::form21(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar, '.'},
        {refChar, refChar, refChar},
    };
}

std::vector<std::vector<char>> Tile::form22(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar},
    };
}

std::vector<std::vector<char>> Tile::form23(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar},
        {refChar, refChar},
    };
}

std::vector<std::vector<char>> Tile::form24(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
    };
}

std::vector<std::vector<char>> Tile::form25(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.', '.'},
        {refChar, refChar, '.', '.'},
        {'.', refChar, refChar, '.'},
        {'.', '.', refChar, refChar},
    };
}

std::vector<std::vector<char>> Tile::form26(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form27(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.'},
        {refChar, refChar, refChar},
        {'.', '.', refChar},
        { '.', '.', refChar }
    };
}

std::vector<std::vector<char>> Tile::form28(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, refChar},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form29(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar},
        {refChar, refChar},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form30(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
        {refChar, refChar, refChar},
        {refChar, '.', refChar}
    };
}

std::vector<std::vector<char>> Tile::form31(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar}
    };
}

std::vector<std::vector<char>> Tile::form32(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.', '.'},
        {refChar, refChar, refChar, '.'},
        {refChar, '.', refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form33(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {'.', refChar},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form34(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, '.', '.'},
        {'.', refChar, '.', '.'},
        {'.', refChar, refChar, refChar},
        {refChar, refChar, '.', '.'},
        {refChar, '.', '.', '.'}
    };
}

std::vector<std::vector<char>> Tile::form35(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, '.'},
        {refChar, refChar},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form36(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {refChar, refChar},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form37(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.', refChar},
        {refChar, refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form38(char refChar) {
    return {
        {'.', '.', '.', static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, '.', '.', '.', refChar},
        {refChar, refChar, refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form39(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.', '.'},
        {refChar, '.', '.', '.'},
        {refChar, refChar, '.', '.'},
        {'.', refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form40(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, '.'},
        {'.', refChar, refChar},
        {refChar, refChar, '.'},
        {'.', refChar, refChar},
        {'.', refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form41(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar},
        {refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form42(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.', '.'},
        {'.', refChar, '.', '.'},
        {refChar, refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form43(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form44(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {refChar, refChar},
        {refChar, refChar},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form45(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {'.', refChar, '.'},
        {refChar, refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form46(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form47(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form48(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.', '.'},
        {refChar, '.', '.', '.'},
        {refChar, refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form49(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar, '.'},
        {refChar, refChar, '.', '.'},
        {'.', refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form50(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, '.'}
    };
}

std::vector<std::vector<char>> Tile::form51(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.'},
        {refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form52(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {'.', '.', refChar, '.', '.'},
        {'.', '.', refChar, '.', '.'},
        {'.', '.', refChar, '.', '.'},
        {refChar, refChar, refChar, '.', '.'},
    };
}

std::vector<std::vector<char>> Tile::form53(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {'.', '.', refChar, '.', '.'},
        {'.', '.', refChar, '.', '.'},
        {'.', '.', refChar, '.', '.'},
        {refChar, refChar, refChar, '.', '.'},
    };
}

std::vector<std::vector<char>> Tile::form54(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {'.', refChar},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, refChar},
        {refChar, '.'}


    };
}

std::vector<std::vector<char>> Tile::form55(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {'.', refChar},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, refChar},
        {refChar, '.'}
        
        
    };
}

std::vector<std::vector<char>> Tile::form56(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar, refChar}
        
        
    };
}

std::vector<std::vector<char>> Tile::form57(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, '.', '.'},
        {'.', refChar, '.', '.'},
        {'.', refChar, refChar, refChar,},
        {'.', '.', '.', refChar}
        
        
        
    };
}

std::vector<std::vector<char>> Tile::form58(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', refChar, '.'},
        {refChar, refChar, refChar},
        {'.', refChar, '.'},
        {'.', refChar, '.'}
    
        
    };
}

std::vector<std::vector<char>> Tile::form59(char refChar) {
    return {
        {'.', '.',static_cast<char>(std::tolower(refChar))},
        {'.', '.', refChar},
        {refChar, refChar, refChar}
          
    };
}

std::vector<std::vector<char>> Tile::form60(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar))},
        {refChar},
        {refChar},
        {refChar},
        {refChar},
        {refChar}
         
    };
}

std::vector<std::vector<char>> Tile::form61(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', refChar},
        {refChar, refChar, refChar},
        {'.', refChar, '.'},
        {refChar, refChar, '.'}
         
    };
}

std::vector<std::vector<char>> Tile::form62(char refChar) {
    return {
        {'.', '.',static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar,refChar, '.'},
        {'.',refChar, refChar,refChar},
        {'.',refChar, '.', '.'}


         
    };
}

std::vector<std::vector<char>> Tile::form63(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
        {refChar, refChar, refChar}
       
    };
}

std::vector<std::vector<char>> Tile::form64(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, '.'},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, '.'}

       
    };
}

std::vector<std::vector<char>> Tile::form65(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, '.', '.'},
        {'.', refChar, '.', '.'},
        {'.', refChar, '.', refChar},
        {refChar, refChar, refChar, refChar}


       
    };
}

std::vector<std::vector<char>> Tile::form66(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar))},
        {'.', refChar, refChar},
        {refChar, refChar, '.'},
        {refChar, '.', '.'},
        {refChar, refChar, '.'}

       
    };
}

std::vector<std::vector<char>> Tile::form67(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
        {refChar, refChar, '.'},
        {refChar, '.', '.'}
       
    };
}

std::vector<std::vector<char>> Tile::form68(char refChar) {
    return {
        { static_cast<char>(std::tolower(refChar)), '.', refChar, '.'},
        { refChar, refChar, refChar, refChar}
       
    };
}

std::vector<std::vector<char>> Tile::form69(char refChar) {
    return {
        { static_cast<char>(std::tolower(refChar)), refChar, '.', '.'},
        { '.', refChar, '.', refChar},
        { '.', refChar, '.', refChar},
        { refChar, refChar, refChar, refChar}
    
    };
}

std::vector<std::vector<char>> Tile::form70(char refChar) {
    return {
        { static_cast<char>(std::tolower(refChar)), '.'},
        { refChar, refChar},
        { refChar, '.'},
        { refChar, '.'},
        { refChar, '.'}
    
    };
}

std::vector<std::vector<char>> Tile::form71(char refChar) {
    return {
        { static_cast<char>(std::tolower(refChar)), '.', '.', '.'},
        {refChar, '.', refChar, '.'},
        {refChar, refChar, refChar, refChar},
        { '.', refChar,'.', '.'},
        { '.', refChar,'.', '.'}
    
    };
}

std::vector<std::vector<char>> Tile::form72(char refChar) {
    return {
        { static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, '.'},
        {refChar, '.'},
        {refChar, '.'},
        {refChar, '.'},
        {refChar, '.'},

    
    };
}

std::vector<std::vector<char>> Tile::form73(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar, refChar},
        {refChar, '.', '.'},
        {refChar, '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form74(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar}

    };
}

std::vector<std::vector<char>> Tile::form75(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar))},
        {refChar, '.', refChar},
        {refChar, refChar, refChar}

    };
}

std::vector<std::vector<char>> Tile::form76(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {refChar, refChar, refChar},
        {refChar, '.', refChar}

    };
}

std::vector<std::vector<char>> Tile::form77(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar)), '.', '.'},
        {'.', '.', refChar, '.', '.'},
        {refChar, refChar, refChar, refChar, refChar},
        {'.', '.', refChar, '.', '.'},
        {'.', '.', refChar, '.', '.'}


    };
}

std::vector<std::vector<char>> Tile::form78(char refChar) {
    return {
        {'.', '.',  '.', static_cast<char>(std::tolower(refChar))},
        {'.', '.',  refChar, refChar},
        {'.', '.',  refChar, '.'},
        {'.', '.',  refChar, '.'},
        {'.', refChar,  refChar, '.'},
        {refChar, refChar,  '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form79(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {refChar, '.', '.'},
        {refChar, refChar, refChar},
        {refChar, '.', '.'},
        {refChar, refChar, refChar}
    };
}

std::vector<std::vector<char>> Tile::form80(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.', '.'},
        {'.', refChar, '.', '.'},
        {'.', refChar, '.', '.'},
        {refChar, refChar, refChar, refChar},
        {'.', refChar, '.', '.'}
    };
}

std::vector<std::vector<char>> Tile::form81(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, '.'},
        {refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form82(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {'.', refChar, '.'},
        {refChar, refChar, '.'},
        {refChar, '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form83(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {'.', refChar, '.'},
        {'.', refChar, refChar},
        {'.', refChar, '.'},
        {'.', refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form84(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, '.'},
        {refChar, refChar, '.'},
        {'.', refChar, refChar},
        {'.', refChar, '.'},
        {'.', refChar, '.'},
        {'.', refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form85(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', refChar, refChar},
        {refChar, refChar, '.'},
        {'.', refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form86(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, '.'},
        {refChar, refChar, refChar}

    };
}

std::vector<std::vector<char>> Tile::form87(char refChar) {
    return {
        {'.', '.', static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar, refChar, '.'},
        {refChar, '.', '.', '.'},
        {refChar, refChar, '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form88(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {'.', refChar, '.'},
        {refChar, refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form89(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', refChar, '.'},
        {refChar, refChar, refChar},
        {'.', refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form90(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), refChar, refChar},
        {refChar,'.', refChar},
        {refChar, '.', '.'},
        {refChar, refChar, '.'}

    };
}

std::vector<std::vector<char>> Tile::form91(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.'},
        {'.', refChar, refChar},
        {refChar, refChar, '.'},
        {refChar, '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form92(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.', '.'},
        {refChar, refChar, '.'},
        {refChar, refChar, refChar}

    };
}

std::vector<std::vector<char>> Tile::form93(char refChar) {
    return {
        {static_cast<char>(std::tolower(refChar)), '.'},
        {refChar,'.'},
        {refChar,'.'},
        {refChar, refChar}

    };
}

std::vector<std::vector<char>> Tile::form94(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), '.', '.'},
        {refChar, refChar, refChar, refChar},
        {refChar, '.', '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form95(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar)), refChar},
        {refChar, refChar, '.'},
        {refChar, '.', '.'},
        {refChar, '.', '.'}

    };
}

std::vector<std::vector<char>> Tile::form96(char refChar) {
    return {
        {'.', static_cast<char>(std::tolower(refChar))},
        {refChar, refChar},
        {refChar, '.'},
        {refChar, refChar}

    };
}   