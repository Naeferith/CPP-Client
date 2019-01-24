// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <sstream>
#include <memory>

#include "Vector2D.h"
#include "Drawable.h"
#include "Visitor.h"
#include "Erreur.h"


# define MY_PI 3.14159265358979323846

# define NETWORK_ERROR		-1
# define GEOMETRIC_ERROR	-2 
# define MAT_ERROR			-3
# define _XML_ERROR			-4