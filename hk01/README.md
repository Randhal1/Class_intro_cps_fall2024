# A formula to calculate multimodal distributions. 
## Randhal Ramirez (11/17/2024)

## Concept:

### As long as the mode is defined as the most repeated value within a list of numbers
### we can compare element-wise using "*_Kronecker-Delta_*" function and then the "*_maximum_*"
### or "*_maxima_*" of the sum of all comparisons for any "*_unique_*" value within the list
### and mathematically this result will be equal to the mode. 

### Note that the terms *_Kronecker-Delta_*, *_maxima_* and *_unique_* are highlighted
### this is because we're going to use these terms to build the C code 

## Basic definitions

## Unique: Single elements without repetition.

## Kronecker-Delta:

# $\displaystyle \delta_{ij} = 0$ if $i \neq j$
# $\displaystyle \delta_{ij} = 1$ if $i = j$

## List of deltas: 

In a list of elements $\delta_{i0}, \delta_{i1},..., \delta_{ij}$ 

## let $\displaystyle {\delta_{ik}}_{k=0}^{j} = \delta_{i0}, \delta_{i1},..., \delta_{ij}$

## Then:

# $Max_{\delta_{ij}} \displaystyle \Sigma_{i = 0}\delta_{ik}$
