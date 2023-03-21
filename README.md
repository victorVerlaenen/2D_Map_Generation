# 2D Map Generator
A 2D map generator that makes random map shapes, using cellular automata to create the layout and marching squares
to smooth the map.

# Generating the noise map
First of all the map is basicly just a grid of booleans. True means that the cell will be a wall and false will be a floor.
The cellular automata algorithm starts from a randomly generated noise map. Changing the noise density will grant different result accourding to your need.

<kbd> 
  <img title="Random noise map with a noise density of 48%" src="https://user-images.githubusercontent.com/97389540/226625261-952c9ce4-9f15-42d0-b486-333de8e0f096.png" width="400"> 
</kbd>     
<kbd> 
  <img title="Random noise map with a noise density of 35%" src="https://user-images.githubusercontent.com/97389540/226629516-a4911e09-e46d-406b-b966-485f0fc146d5.png" width="400"> 
</kbd>

## Seed
The generator also works with a seed, so you can always regenerate a map you liked.

# Cellular Automata


# Marching Squares

