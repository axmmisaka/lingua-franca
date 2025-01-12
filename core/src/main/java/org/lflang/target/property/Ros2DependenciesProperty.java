package org.lflang.target.property;

import java.util.ArrayList;
import java.util.List;
import org.lflang.MessageReporter;
import org.lflang.ast.ASTUtils;
import org.lflang.lf.Element;
import org.lflang.lf.KeyValuePair;
import org.lflang.lf.LfPackage.Literals;
import org.lflang.lf.Model;
import org.lflang.target.property.type.ArrayType;

/** Directive to specify additional ROS2 packages that this LF program depends on. */
public final class Ros2DependenciesProperty extends TargetProperty<List<String>, ArrayType> {

  /** Singleton target property instance. */
  public static final Ros2DependenciesProperty INSTANCE = new Ros2DependenciesProperty();

  private Ros2DependenciesProperty() {
    super(ArrayType.STRING_ARRAY);
  }

  @Override
  public List<String> initialValue() {
    return new ArrayList<>();
  }

  @Override
  public List<String> fromAst(Element node, MessageReporter reporter) {
    return ASTUtils.elementToListOfStrings(node);
  }

  @Override
  protected List<String> fromString(String string, MessageReporter reporter) {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  @Override
  public void validate(KeyValuePair pair, Model ast, MessageReporter reporter) {
    var ros2enabled = TargetProperty.getKeyValuePair(ast, Ros2Property.INSTANCE);
    if (pair != null && (ros2enabled == null || !ASTUtils.toBoolean(ros2enabled.getValue()))) {
      reporter
          .at(pair, Literals.KEY_VALUE_PAIR__NAME)
          .warning("Ignoring ros2-dependencies as ros2 compilation is disabled");
    }
  }

  @Override
  public Element toAstElement(List<String> value) {
    return ASTUtils.toElement(value);
  }

  @Override
  public String name() {
    return "ros2-dependencies";
  }
}
