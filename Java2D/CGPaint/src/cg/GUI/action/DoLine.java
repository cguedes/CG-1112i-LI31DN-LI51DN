package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.CGPaint;
import cg.GUI.IRasterDevice;


public class DoLine extends PerformNPointsAction {

	// Este comando precisa de 2 pontos
	public DoLine() { super(2); }

	
	public void doAction(CGPaint cg, Point[] points)
	{
		Point start = points[0];
		Point end = points[1];

		IRasterDevice dc = cg.getRasterDisplay();
		cg.getCurrentLineAlgorithm().drawLine(dc, start, end, cg.getCurrentColor());
		dc.addLine(start, end);
		dc.writePixel(start.x, start.y, Color.RED);
		dc.writePixel(end.x, end.y, Color.RED);
	}
	
	public void drawAction(CGPaint cg, Point[] points, int nPoints, Point mousePos){
		if(nPoints == 1){
			points[nPoints] = mousePos;
			cg.drawInfoLines(points, nPoints+1);
		}
	}	
}
