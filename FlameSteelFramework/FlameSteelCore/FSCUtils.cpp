/*
 * FSCUtils.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#include "FSCUtils.h"

#include <stdlib.h>
#include <time.h>

FSCUtils::FSCUtils() {
    // TODO Auto-generated constructor stub

}

int FSCUtils::FSCRandomInt(int maximalInt) {


    if (maximalInt == 0) {

        return 0;

    }

    int randomUInt = rand() % maximalInt;

    return randomUInt;
}

shared_ptr<string> FSCUtils::localizedString(shared_ptr<string> key) {

    return key;
}

FSCUtils::~FSCUtils() {
    // TODO Auto-generated destructor stub
}
