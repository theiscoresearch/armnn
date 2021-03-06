//
// Copyright © 2017 Arm Ltd. All rights reserved.
// See LICENSE file in the project root for full license information.
//
#pragma once

#include "LayerWithParameters.hpp"

namespace armnn
{

class MergerLayer : public LayerWithParameters<OriginsDescriptor>
{
public:
    virtual std::unique_ptr<IWorkload> CreateWorkload(const Graph&            graph,
                                                      const IWorkloadFactory& factory) const override;
    virtual void CreateTensorHandles(Graph& graph, const IWorkloadFactory& factory) override;

    MergerLayer* Clone(Graph& graph) const override;

    void ValidateTensorShapesFromInputs() override;

protected:
    MergerLayer(const OriginsDescriptor& param, const char* name);
    ~MergerLayer() = default;
};

} // namespace
