package cg.GUI;

import java.awt.Color;
import java.awt.Point;

public class PointRGB extends Point {

	private static final long serialVersionUID = 7430753382515302114L;

	/**
	 */
	public Color color;
	
	public PointRGB(int x, int y) {
		this(x, y, Color.BLACK);
	}
	
	public PointRGB(Point p) {
		this(p, Color.BLACK);
	}
	
	public PointRGB(Point p, Color color) {
		this(p.x, p.y, color);
	}
	
	public PointRGB(int x, int y, Color color) {
		super(x, y);
		this.color = color;
	}
	

}
