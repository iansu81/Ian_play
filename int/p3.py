function polygonArea(X, Y, numPoints)
{
    area = 0
    // Accumulates area
    j = numPoints-1

    for (i=0
         i < numPoints
         i++)
    {area += (X[j]+X[i]) * (Y[j]-Y[i])
     j = i
     // j is previous vertex to i
     }
    return area/2
}
