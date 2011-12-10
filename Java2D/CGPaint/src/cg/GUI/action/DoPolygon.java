package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;
import java.util.LinkedList;

import cg.GUI.CGPaint;
import cg.algorithms.polygon.PolygonAlgorithmChooser;
import cg.common.ColorPoint;

/**
 * ... 
 */
public abstract class DoPolygon implements IPerformAction {
	
	private Point[] points = null;
	private Color[] colors = null;
	private LinkedList<ColorPoint> colorPointsList; 
	private ColorPoint firstPoint;
	
	public DoPolygon() {
		colorPointsList = new LinkedList<ColorPoint>();
	}
	
	public void doAction(CGPaint cg, Point pos, Color color) {
		if(colorPointsList.size() == 0)
			firstPoint = new ColorPoint(pos, color);
		// Regista-se o ponto na posição actual
		colorPointsList.add( new ColorPoint(pos, color) );
		cg.getRasterDisplay().writePixel(pos.x, pos.y, Color.GREEN);
		
		if( colorPointsList.size() > 1 && pos.equals(firstPoint.point) ) {
			points = new Point[colorPointsList.size()-1];
			colors = new Color[colorPointsList.size()-1];
			for(int i = 0; i < colorPointsList.size()-1; ++i) 
			{
				points[i] = colorPointsList.get(i).point;
				colors[i] = colorPointsList.get(i).color;
			}
			
			colorPointsList.clear();
			doAction(cg, points, colors);
			
		}
	}
	public void drawAction(CGPaint cg, Point mousePos, Color color){
		
		if(colorPointsList.size() >= 1) {
			Point[] points = new Point[colorPointsList.size()+1];
			int i = 0;
			for(; i < colorPointsList.size(); ++i)
				points[i] = colorPointsList.get(i).point;
			points[i] = new Point(mousePos);
			cg.drawInfoLines(points, points.length);
		}
		
	}
	
	public abstract void doAction(CGPaint cg, Point[] points, Color[] colors);

	
}
