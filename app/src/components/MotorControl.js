import React, { Component } from 'react';
import { connect } from 'react-redux'
import styled from 'styled-components';
import { motorUnload, motorLoad, motorOff } from '../actions/control';

const MotorControlWrapper = styled.div`
    margin: 8px;
`;

class MotorControl extends Component {
    handleLoad = () => this.props.onLoadClick();
    handleUnload = () => this.props.onUnloadClick();
    handleOff = () => this.props.onOffClick();

    render() {
        return (
            <MotorControlWrapper>
                {"MOTOR: "}{this.props.id}{" "}
                <button onClick={this.handleUnload}>
                    {"UNLOAD"}
                </button>
                <button onClick={this.handleOff}>
                    {"OFF"}
                </button>
                <button onClick={this.handleLoad}>
                    {"LOAD"}
                </button>
            </MotorControlWrapper>
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
