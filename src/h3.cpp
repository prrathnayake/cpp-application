#include <iostream>

#include <h3/index.h>
#include <h3/h3api.h>

int main()
{
    h3::H3 *h3Object = new h3::H3();

    H3Index index = h3Object->getH3Index(40.689167, -74.044444, 10);
    std::cout << "Index is " << index << "\n";

    CellBoundary boundary = h3Object->getBoundaries(index);

    for (int v = 0; v < boundary.numVerts; v++)
    {
        printf("Boundary vertex #%d: %lf, %lf\n", v,
               radsToDegs(boundary.verts[v].lat),
               radsToDegs(boundary.verts[v].lng));
    }

    LatLng center = h3Object->getCenter(index);

    printf("Center coordinates: %lf, %lf\n", radsToDegs(center.lat),
           radsToDegs(center.lng));

    delete h3Object;

    return 0;
}