//
// Created by User on 14.04.2025.
//
#ifndef SD_1_LISTA_MAIN_MENU_H
#define SD_1_LISTA_MAIN_MENU_H
#endif //SD_1_LISTA_MAIN_MENU_H
#pragma once
#include <string>
#include "BaseList.hpp"

void showMenu();
void showOperationMenu();
template<class T>
void performListOperations(BaseList<T>& list, const std::string& listName);
void runMenu();
