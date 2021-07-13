/*
 * generated by Xtext 2.23.0
 */
package org.lflang;

import org.eclipse.xtext.resource.IDefaultResourceDescriptionStrategy;
import org.eclipse.xtext.scoping.IGlobalScopeProvider;
import org.eclipse.xtext.validation.INamesAreUniqueValidationHelper;
import org.lflang.scoping.LFGlobalScopeProvider;
import org.lflang.validation.LFNamesAreUniqueValidationHelper;

/**
 * Use this class to register components to be used at runtime / without the
 * Equinox extension registry.
 */
public class LFRuntimeModule extends AbstractLFRuntimeModule {

    /** Establish a binding to our custom resource description strategy. */
    public Class<? extends IDefaultResourceDescriptionStrategy> bindIDefaultResourceDescriptionStrategy() {
        return LFResourceDescriptionStrategy.class;
    }

    /** Establish a binding to our custom global scope provider. */
    @Override
    public Class<? extends IGlobalScopeProvider> bindIGlobalScopeProvider() {
        return LFGlobalScopeProvider.class;
    }

    /** Establish a binding to a helper that checks that names are unique. */
    public Class<? extends INamesAreUniqueValidationHelper> bindNamesAreUniqueValidationHelper() {
        return LFNamesAreUniqueValidationHelper.class;
    }

}