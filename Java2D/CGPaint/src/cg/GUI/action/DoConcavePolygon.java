package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.CGPaint;
import cg.algorithms.polygon.PolygonAlgorithmChooser;

/**
 * ... 
 */
public class DoConcavePolygon extends DoPolygon {
	
	public void doAction(CGPaint cg, Point[] points, Color[] colors) {
		// Chamada ao algoritmo de preenchimento de poligonos convexos
		PolygonAlgorithmChooser.getAlgorithm("ConcavePolygonFill").fillPolygon( cg.getRasterDisplay(), points, colors );
	}
	
}
