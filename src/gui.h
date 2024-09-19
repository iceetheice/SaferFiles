#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <raylib.h>

#include "../include/raygui.h"

#include "encryption.h"


static FILE *file = NULL;
static char *text;
static int key;


// ui stuff
static char inputPath[1024];
static bool inputPathActive = false;
static char inputKey[100];
static bool inputKeyActive = false;

void updateGUI();

void drawGUI();