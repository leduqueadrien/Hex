
#include "gameUtils.hpp"

Neighbour & operator++(Neighbour& n) {
	n = static_cast<Neighbour>(static_cast<int>(n)+1);
	return n;
}
