/* alloc_lib.c -- allocates for fractal images

  Copyright 2016-2017 ChemicalDevelopment

  This file is part of the FractalRender project.

  FractalRender source code, as well as any other resources in this project are
free software; you are free to redistribute it and/or modify them under
the terms of the GNU General Public License; either version 3 of the
license, or any later version.

  These programs are hopefully useful and reliable, but it is understood
that these are provided WITHOUT ANY WARRANTY, or MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GPLv3 or email at
<info@chemicaldevelopment.us> for more info on this.

  Here is a copy of the GPL v3, which this software is licensed under. You
can also find a copy at http://www.gnu.org/licenses/.

*/


#ifndef __ALLOC_LIB_H__
#define __ALLOC_LIB_H__

#include "fractalrender.h"

FILE * sfopen(char *fn, char *mode);

void fr_dft_clr(fractal_img_t * ret, double zn, int ci, double er2,int col_dest);

void init_frit(fractal_img_t *ret, long px, long py, long max_iter);

void init_frcl(fractal_color_t *ret);

#endif
