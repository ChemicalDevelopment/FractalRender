/* c_engine/engine_c.c -- C engine for computing fractals

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


#include "fractalrender.h"


void engine_c_fulltest(fractal_img_t * ret) {

    long x, y, ci;

    double ssxd = atof(ret->cX) - 1.0 / atof(ret->Z), ssyd = atof(ret->cY) + ret->py / (ret->px * atof(ret->Z));

    double d_xd = 2.0 / (ret->px * atof(ret->Z)), d_yd = -2.0 / (ret->px * atof(ret->Z));

    double xd, yd, tmp, sxd, syd, xds, yds;

    double er = 16.0;
    double er2 = er * er;


    int col_dest;

    for (x = 0; x < ret->px; ++x) {
        for (y = 0; y < ret->py; ++y) {
            col_dest = 3 * (y * ret->px + x);
            xd = ssxd + x * d_xd;
            yd = ssyd + y * d_yd;
            sxd = xd, syd = yd;
            xds = xd * xd, yds = yd * yd;
            
            for (ci = 1; ci <= ret->max_iter && xds + yds <= er2; ++ci) {
                tmp = 2 * xd * yd;
                xd = xds - yds + sxd;
                yd = tmp + syd;
                xds = xd * xd;
                yds = yd * yd;
            }

            if (ret->color.is_simple) {
                int color_off;
                if (ci > ret->max_iter) {
                    color_off = 0;
                } else {
                    color_off = 3*((int)floor(ci * ret->color.mult + ret->color.disp) % ret->color.numcol);
                }
                ret->data[col_dest + 0] = ret->color.data[color_off + 0];
                ret->data[col_dest + 1] = ret->color.data[color_off + 1];
                ret->data[col_dest + 2] = ret->color.data[color_off + 2];
                
            } else {
                double zn = xds + yds;
                double hue;
                if (zn <= er2) {
                    hue = 0;
                } else {
                    hue = ci + 1.0 - log(fabs(zn)) / log(er2);
                }

                hue = hue * ret->color.mult + ret->color.disp;
                
                hue = fmod(fmod(hue, ret->color.numcol) + ret->color.numcol, ret->color.numcol);

                tmp = hue - floor(hue);
                int color_off0 = 3 * ((int)floor(hue) % ret->color.numcol);
                int color_off1;
                if (color_off0 >= 3 *(ret->color.numcol - 1)) {
                    color_off1 = 0;
                } else {
                    color_off1 = color_off0 + 3;
                }

                ret->data[col_dest + 0] = ((unsigned char)floor(tmp*ret->color.data[color_off1 + 0]+(1-tmp)*ret->color.data[color_off0 + 0]));
                ret->data[col_dest + 1] = ((unsigned char)floor(tmp*ret->color.data[color_off1 + 1]+(1-tmp)*ret->color.data[color_off0 + 1]));
                ret->data[col_dest + 2] = ((unsigned char)floor(tmp*ret->color.data[color_off1 + 2]+(1-tmp)*ret->color.data[color_off0 + 2]));
            }
        }
    }
}


