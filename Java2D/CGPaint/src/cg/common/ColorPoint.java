package cg.common;

import java.awt.Color;
import java.awt.Point;

public class ColorPoint {
	public Point point;
	public Color color = Color.BLACK;
	public ColorPoint(Point p) { 
		point = p;
	}
	public ColorPoint(Point p, Color c) {
		this(p);
		color = c;
	}
}