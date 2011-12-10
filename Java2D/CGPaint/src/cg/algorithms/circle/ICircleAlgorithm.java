package cg.algorithms.circle;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public interface ICircleAlgorithm {

	void drawCircle(IRasterDevice dc, Point center, int radius);
	void drawCircle(IRasterDevice dc, Point center, int radius, Color color);
	
	void fillCircle(IRasterDevice dc, Point center, int radius);
	void fillCircle(IRasterDevice dc, Point center, int radius, Color color);
}
