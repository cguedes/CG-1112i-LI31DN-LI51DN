package cg.algorithms.polygon;

import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;


public final class PolygonAlgorithmChooser {

	private static Dictionary<String, IPolygonFillAlgorithm> algorithms = new Hashtable<String, IPolygonFillAlgorithm>();
	
	static {		
		algorithms.put("ConvexPolygonFill", new ConvexPolygonFillAlgorithm());
		algorithms.put("ConcavePolygonFill", new ConcavePolygonFillAlgorithm());
	}
	
	public static Enumeration<String> getAvailableAlgorithms() {
		return algorithms.keys();
	}
	
	public static IPolygonFillAlgorithm getAlgorithm(String algName) {
		return algorithms.get(algName);
	}
	
	public static IPolygonFillAlgorithm getDefaultAlgorithm() {
		return algorithms.get(algorithms.keys().nextElement());
	}
	
	
	
}
