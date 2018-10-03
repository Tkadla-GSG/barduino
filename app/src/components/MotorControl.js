import React, { Component } from 'react';
import { connect } from 'react-redux'
import { brewBeverage } from '../actions/beverage';
import { motorUnload, motorLoad, motorOff } from '../actions/control';

class MotorControl extends Component {
    handleLoad = () => this.props.onLoadClick();
    handleUnload = () => this.props.onUnloadClick();
    handleOff = () => this.props.onOffClick();

    render() {
        return (
            <div>
                <button onClick={this.handleUnload}>
                    {"UNLOAD"}
                </button>
                <button onClick={this.handleOff}>
                    {"OFF"}
                </button>
                <button onClick={this.handleLoad}>
                    {"LOAD"}
                </button>
            </div>
        );
    }
}

export default connect(
    undefined,
    (dispatch, { id }) => ({
        onUnloadClick: () => dispatch(motorUnload(id)),
        onLoadClick: () => dispatch(motorLoad(id)),
        onOffClick: () => dispatch(motorOff(id)),
    })
)(MotorControl);
