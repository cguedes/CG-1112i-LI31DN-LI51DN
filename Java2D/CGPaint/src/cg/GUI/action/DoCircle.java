package cg.GUI.action;

import java.awt.Point;

import cg.GUI.CGPaint;
import cg.GUI.IRasterDevice;


public class DoCircle extends PerformNPointsAction {

	// Este comando precisa de 2 pontos
	public DoCircle() { super(2); }
	
	public void doAction(CGPaint cg, Point[] points)
	{
		Point start = points[0];
		Point end = points[1];

		IRasterDevice dc = cg.getRasterDisplay();
		int radius = (int) Math.abs(end.distance(start));
		
		cg.getCurrentCircleAlgorithm().drawCircle(dc, start, radius, cg.getCurrentColor());
		
		dc.addCircle(start, radius);
	}
	
	public void drawAction(CGPaint cg, Point[] points, int nPoints, Point mousePos){
		if(nPoints == 1){
			cg.drawInfoCircle(points[0], mousePos);
		}
	}	

}
