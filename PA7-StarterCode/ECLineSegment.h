//
//  ECLineSegment.h
//  
//
//  Created by Yufeng Wu on 1/22/21.
//
//

#ifndef ECLineSegment_h
#define ECLineSegment_h

// -----------------------------------------------------------------------------
// Point on 2D plane

class EC2DPoint
{
public:
    EC2DPoint(double x, double y);
    // your code goes here
    
private:
    // your code goes here
};

// -----------------------------------------------------------------------------
// Line segment on 2D plane

class ECLineSegment
{
public:
    ECLineSegment(const EC2DPoint &pStart, const EC2DPoint &pEnd);
    
    // Is this segment intersect with the other?
    bool IsIntersect(const ECLineSegment &rhs) const;
    
    // your code goes here
    
private:
    // your code goes here
};


#endif /* ECLineSegment_h */
