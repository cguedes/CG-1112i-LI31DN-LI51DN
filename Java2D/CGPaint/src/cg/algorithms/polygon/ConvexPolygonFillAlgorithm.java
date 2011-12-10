package cg.algorithms.polygon;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public class ConvexPolygonFillAlgorithm implements IPolygonFillAlgorithm
{

	public void fillPolygon(IRasterDevice dc, Point[] points, Color[] colors) 
	{
		// A implementar
		for(int i = 0; i < points.length; ++i) {
			dc.writePixel(points[i].x, points[i].y, colors[i]);
		}

	}
	

}
