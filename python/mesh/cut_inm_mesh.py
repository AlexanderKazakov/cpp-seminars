#!/usr/bin/env python3

import pandas as pd
import numpy as np

skull = pd.read_csv('mesh-coarse.out', sep = ' ', names = ['A', 'B', 'C', 'D', 'E'])

num_points = int(skull.A[0])
num_cells = int(skull.A[num_points+1])

x = skull.A[1:num_points+1]
y = skull.B[1:num_points+1]
z = skull.C[1:num_points+1]
r = np.c_[x, y, z]

cells2 = np.c_[skull.A, skull.B, skull.C, skull.D]
cells = cells2[num_points+2:-1].astype(int)
cells = cells - 1 # to zero-based indexing

materials = skull.E[num_points+2:-1].astype(int)

cells_by_points = r[cells]
cells_centers = cells_by_points.sum(axis=1) / 4

sphere_radius = 30
sphere_center = np.array([0, 75, 1420])

directions = cells_centers - sphere_center
dist2 = (directions**2).sum(axis=1)
is_our_cells = dist2 < sphere_radius**2

our_cells = cells[is_our_cells]
our_cells_flat = our_cells.ravel()

our_poins = np.unique(our_cells_flat)
our_poins.sort()
new_points = r[our_poins]

our_cells_flat_x, our_poins_x = np.ix_(our_cells_flat, our_poins)
match_table = (our_cells_flat_x == our_poins_x).astype(int)

new_points_indices = np.arange(1, our_poins.size+1)
match_table = match_table * new_points_indices

new_materials = materials[is_our_cells]
new_cells = match_table.sum(axis=1).reshape(our_cells.shape)
new_cells_with_materials = np.c_[new_cells, new_materials]

f = open('skull_part.out', 'w')
f.close()
f = open('skull_part.out', 'ab')
f.write((str(new_points.shape[0]) + '\n').encode())
np.savetxt(f, new_points, delimiter=' ')
f.write((str(new_cells_with_materials.shape[0]) + '\n').encode())
np.savetxt(f, new_cells_with_materials, delimiter=' ', fmt='%d')
f.write(b'0\n')
f.close()

