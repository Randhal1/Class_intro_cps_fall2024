# A formula to calculate multimodal distributions. 

## Concept:

### As long as the mode is defined as the most repeated value within a list of numbers
### we can compare element-wise using "*_Kronecker-Delta_*" function and then the "*_maximum_*"
### or "*_maxima_*" of the sum of all comparisons for any "*_unique_*" value within the list
### and mathematically this result will be equal to the mode. 

### Note that the terms *_Kronecker-Delta_*, *_maxima_* and *_unique_* are highlighted
### this is because we're going to use these terms to build the C code 

## Basic definitions

## Kronecker-Delta:

$\displaystyle \delta_{ij} = $ 
