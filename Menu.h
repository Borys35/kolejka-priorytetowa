#pragma once

#include <string>
#include "BaseList.hpp"

void showMenu();
void showOperationMenu();
template<class T>
void performListOperations(BaseList<T>& list, const std::string& listName);
void runMenu();
