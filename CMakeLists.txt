cmake_minimum_required(VERSION 3.15)
project(Projet_POO_git)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(DOC_TEST)
include_directories(winbgi)

add_executable(Projet_POO_git
        DOC_TEST/doctest.h
        winbgi/CodeBlocks/graphics.h winbgi/CodeBlocks/winbgi.cpp
        debris.cpp debris.h
        jeu.cpp jeu.h
        joueur.cpp joueur.h
        joueurBase.cpp joueurBase.h 
        joueurExpert.cpp joueurExpert.h
        mur.cpp mur.h
        objet.cpp objet.h
        robot.cpp robot.h
        terrain.cpp terrain.h
        robotAncien.cpp robotAncien.h
        robotNouveau.cpp robotNouveau.h
        robotPerso.cpp robotPerso.h
        TestRobotPerso.cpp
        TestRobotAncien.cpp
        TestRobotNouveau.cpp
        testDebris.cpp
        testJoueurBase.cpp
        testJoueurExpert.cpp
        testMur.cpp
        TestTerrain.cpp
        mainTestTerrain.cpp
        main.cpp )
