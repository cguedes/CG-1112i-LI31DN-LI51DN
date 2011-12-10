package cg.algorithms.triangle;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public interface ITriangleFillAlgorithm 
{

	void fillTriangle(IRasterDevice dc, Point p1, Point p2, Point p3, Color c1, Color c2, Color c3); 

}
