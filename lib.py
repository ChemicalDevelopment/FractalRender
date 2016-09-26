#Currently testing
import cmath
import random

#Returns the iterations of (x+iy). Returns 0 through maxIterations inclusive
def rawIterations_mand(x, y, maxIterations):
    re = x
    im = y
    iter = 0
    while re * re + im * im < 4 and iter < maxIterations:
        tmp = 2 * re * im
        re = re * re - im * im + x
        im = tmp + y
        iter += 1
    return iter

#Returns the iterations of (x+iy). Returns 0 through maxIterations inclusive
def rawIterations(x, y, maxIterations, func):
    z = 0 + 0j
    c = x + y*1j
    iter = 0
    while z.imag * z.imag + z.real * z.real <= 4 and iter < maxIterations:
        try:
            z = eval(func)
        except:
            z = c
        #tmp = 2 * re * im
        #re = re * re - im * im + x
        #im = tmp + y
        iter += 1
    return iter

#Colorizes based on pattern
def colorize(pattern, iter, maxIterations):
    pattern = pattern.upper()
    if pattern == "MOCHA":
        piter = ((maxIterations - iter) % 256) / 255.0
        return (int(256 * piter), int(256 * piter * piter), int(256 * piter * piter * piter))
    elif pattern == "RANDOM":
        piter = ((maxIterations * iter - iter * 3 + 5) % 256 ) / 255.0
        return (int(256 * piter), int(256 * piter * piter), int(256 * piter * piter * piter))
    else:
        cbit = int(256 * iter / maxIterations)
        return (cbit, cbit, cbit)
