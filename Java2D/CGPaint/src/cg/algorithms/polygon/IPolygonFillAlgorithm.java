package cg.algorithms.polygon;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public interface IPolygonFillAlgorithm 
{

	void fillPolygon(IRasterDevice dc, Point[] points, Color[] colors); 

}
